/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:06:54 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 15:45:19 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	can_move(t_cub3d *all, double x, double y)
{
	int	map_x;
	int	map_y;
	int	i;

	map_x = (int)floor(x);
	map_y = (int)floor(y);
	i = 0;
	if (map_y < 0 || map_y >= (int)all->data->ymax)
		return (0);
	if (map_x < 0 || map_x >= (int)hb_strlen(all->map[map_y]))
		return (0);
	if (!all->map[map_y])
		return (0);
	if (all->map[(int)all->player_y][map_x] == '1'
		|| all->map[map_y][(int)all->player_x] == '1')
		return (0);
	if (all->map[(int)all->player_y][map_x] == 'D'
		|| all->map[map_y][(int)all->player_x] == 'D')
		return (0);
	return (1);
}

int	is_ficing_direct(double angle)
{
	angle = normalize_angle(angle);
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	if (fabs(angle - 0) < EPSILON || fabs(angle - M_PI) < EPSILON || fabs(angle
			- M_PI_2) < EPSILON || fabs(angle - 3 * M_PI_2) < EPSILON)
		return (1);
	return (0);
}

void	move_player(t_cub3d *data, double newx, double newy)
{
	if (can_move(data, newx, newy))
	{
		if (can_move(data, newx, data->player_y))
			data->player_x = newx;
		if (can_move(data, data->player_x, newy))
			data->player_y = newy;
	}
	else
	{
		if (is_ficing_direct(data->player_angle))
			return ;
		else if (can_move(data, newx, data->player_y))
			data->player_x = newx;
		else if (can_move(data, data->player_x, newy))
			data->player_y = newy;
	}
}

void	close_door(t_cub3d *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	while (j < 8)
	{
		i = 1;
		while (i < 3)
		{
			x = (int)data->player_x + (dirs(j, 0) * i);
			y = (int)data->player_y + (dirs(j, 1) * i);
			if (x >= 0 && y >= 0 && x < (int)data->data->xmax
				&& y < (int)data->data->ymax)
			{
				if (data->map[y][x] == 'O')
					data->map[y][x] = 'D';
			}
			i++;
		}
		j++;
	}
}

void	open_door(t_cub3d *data)
{
	int (i), (dir), (found_door), (x), (y);
	found_door = 0;
	dir = 0;
	while (dir < 8)
	{
		i = 1;
		while (i < 3)
		{
			x = (int)data->player_x + (dirs(dir, 0) * i);
			y = (int)data->player_y + (dirs(dir, 1) * i);
			if (x >= 0 && y >= 0 && x < (int)data->data->xmax
				&& y < (int)data->data->ymax)
			{
				if (data->map[y][x] == 'D')
				{
					data->map[y][x] = 'O';
					found_door = 1;
				}
			}
			i++;
		}
		dir++;
	}
	if (!found_door)
		close_door(data);
}
