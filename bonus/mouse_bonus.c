/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:28:38 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	rotation_rows(t_cub3d *data, int keycode)
{
	if (keycode == LEFT)
		data->player_angle -= 0.05;
	else if (keycode == RIGHT)
		data->player_angle += 0.05;
}

int	mouse_move(int x, int y, t_cub3d *data)
{
	int		center_x;
	int		delta_x;
	double	sensitivity;

	(void)y;
	center_x = WINDOW_WIDTH / 2;
	sensitivity = 0.002;
	delta_x = x - center_x;
	if (abs(delta_x) > 5)
	{
		data->player_angle += delta_x * sensitivity;
		while (data->player_angle < 0)
			data->player_angle += 2 * M_PI;
		while (data->player_angle >= 2 * M_PI)
			data->player_angle -= 2 * M_PI;
		mlx_mouse_move(data->mlx, data->win, center_x, WINDOW_HEIGHT / 2);
		render(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (0);
}
