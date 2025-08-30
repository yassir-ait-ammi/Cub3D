/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:40:00 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/27 14:13:51 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	step_dir(t_cub3d *data, t_dda *var)
{
	if (data->ray_dir_x < 0)
	{
		var->step_x = -1;
		var->side_dist_x = (data->player_x - var->map_x) * var->delta_dist_x;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1.0 - data->player_x)
			* var->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (data->player_y - var->map_y) * var->delta_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1.0 - data->player_y)
			* var->delta_dist_y;
	}
}

void	hit_wall(t_cub3d *data, t_dda *var)
{
	if (var->map_x >= 0 && var->map_x < (int)data->data->xmax
		&& var->map_y >= 0 && var->map_y < (int)data->data->ymax)
	{
		if (data->map[var->map_y][var->map_x] == '1')
		{
			var->hit = 1;
			data->hitype = 0;
		}
		if (data->map[var->map_y][var->map_x] == 'D')
		{
			var->hit = 1;
			data->hitype = 1;
		}
	}
}

void	dda_loop(t_cub3d *data, t_dda *var)
{
	while (!var->hit && var->map_x >= 0 && var->map_x < (int)data->data->xmax
		&& var->map_y >= 0 && var->map_y < (int)data->data->ymax)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->delta_dist_x;
			var->map_x += var->step_x;
			*data->hitside = 0;
		}
		else
		{
			var->side_dist_y += var->delta_dist_y;
			var->map_y += var->step_y;
			*data->hitside = 1;
		}
		hit_wall(data, var);
	}
}

double	distance(t_cub3d *data, t_dda *var)
{
	double	dist;

	if (!var->hit)
		return (-1.0);
	if (*data->hitside == 0)
	{
		dist = (var->map_x - data->player_x + (1 - var->step_x) / 2.0)
			/ data->ray_dir_x;
		data->wall = data->player_y + dist * data->ray_dir_y;
	}
	else
	{
		dist = (var->map_y - data->player_y + (1 - var->step_y) / 2.0)
			/ data->ray_dir_y;
		data->wall = data->player_x + dist * data->ray_dir_x;
	}
	data->wall -= floor(data->wall);
	return (dist);
}

double	dda(t_cub3d *data)
{
	t_dda	var;

	data->ray_dir_x = cos(data->player_angle);
	data->ray_dir_y = sin(data->player_angle);
	var.map_x = (int)data->player_x;
	var.map_y = (int)data->player_y;
	var.delta_dist_x = fabs(1.0 / data->ray_dir_x);
	var.delta_dist_y = fabs(1.0 / data->ray_dir_y);
	var.hit = 0;
	step_dir(data, &var);
	dda_loop(data, &var);
	return (distance(data, &var));
}
