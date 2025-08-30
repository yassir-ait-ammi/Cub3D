/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:18:53 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:31:48 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clean_exit(t_cub3d *all)
{
	if (all->we_tex.img)
		mlx_destroy_image(all->mlx, all->we_tex.img);
	if (all->no_texture.img)
		mlx_destroy_image(all->mlx, all->no_texture.img);
	if (all->so_texture.img)
		mlx_destroy_image(all->mlx, all->so_texture.img);
	if (all->ea_texture.img)
		mlx_destroy_image(all->mlx, all->ea_texture.img);
	if (all->img.img)
		mlx_destroy_image(all->mlx, all->img.img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->mlx)
	{
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	return (ft_exit(0), 177777);
}

int	dirs(int i, int j)
{
	static int	direction[8][2] = {{0, -1},
	{1, -1},
	{1, 0},
	{1, 1},
	{0, 1},
	{-1, 1},
	{-1, 0},
	{-1, -1}};

	return (direction[i][j]);
}

static void	handle_move_keys(int keycode, t_cub3d *data, double move_speed)
{
	double (newx), (newy);
	if (keycode == 119)
	{
		newx = data->player_x + cos(data->player_angle) * move_speed;
		newy = data->player_y + sin(data->player_angle) * move_speed;
		move_player(data, newx, newy);
	}
	else if (keycode == 115)
	{
		newx = data->player_x - cos(data->player_angle) * move_speed;
		newy = data->player_y - sin(data->player_angle) * move_speed;
		move_player(data, newx, newy);
	}
	else if (keycode == 100)
	{
		newx = data->player_x + cos(data->player_angle + M_PI_2) * move_speed;
		newy = data->player_y + sin(data->player_angle + M_PI_2) * move_speed;
		move_player(data, newx, newy);
	}
	else if (keycode == 97)
	{
		newx = data->player_x + cos(data->player_angle - M_PI_2) * move_speed;
		newy = data->player_y + sin(data->player_angle - M_PI_2) * move_speed;
		move_player(data, newx, newy);
	}
}

int	key_press(int keycode, t_cub3d *data)
{
	double (move_speed);
	(1) && (move_speed = 0.1);
	if (keycode == 65307 || keycode == 17)
		clean_exit(data);
	else if (keycode == 119 || keycode == 115 || keycode == 100
		|| keycode == 97)
		handle_move_keys(keycode, data, move_speed);
	else if (keycode == LEFT || keycode == RIGHT)
		rotation_rows(data, keycode);
	else
		return (1);
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
