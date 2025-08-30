/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:46 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_all(t_cub3d *all)
{
	all->we_tex.img = NULL;
	all->no_texture.img = NULL;
	all->so_texture.img = NULL;
	all->ea_texture.img = NULL;
	all->dor_tex.img = NULL;
	all->img.img = NULL;
	all->win = NULL;
	all->mlx = NULL;
	all->por_tex = NULL;
	all->map = hb_split(all->data->map, '\n');
	all->data->xmax = get_maxwidth(all->map);
	all->data->ymax = hb_mtrlen(all->map);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "awdii");
	all->img.img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img,
			&all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	all->teleporting = 0;
	all->anim_current_frame = 0;
	all->anim_max_frames = 32;
	all->anim_frame_delay = 3;
	all->anim_delay_counter = 0;
	all->anim_active = 0;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	ft_exit(int nb)
{
	ft_malloc(0, FT_CLEAR);
	exit(nb);
}
