/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:02:23 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:41:57 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	tern_portal(t_por *p)
{
	if (p->tex_x < 0)
		p->tex_x = 0;
	if (p->tex_y < 0)
		p->tex_y = 0;
}

void	draw_portal(t_cub3d *all, t_img *texture)
{
	t_por	p;

	p.scale_x = (float)texture->txtr_w / (float)WINDOW_WIDTH;
	p.scale_y = (float)texture->txtr_h / (float)WINDOW_HEIGHT;
	p.screen_y = 0;
	while (p.screen_y < WINDOW_HEIGHT)
	{
		p.screen_x = 0;
		while (p.screen_x < WINDOW_WIDTH)
		{
			p.tex_x = (int)(p.screen_x * p.scale_x);
			p.tex_y = (int)(p.screen_y * p.scale_y);
			if (p.tex_x >= texture->txtr_w)
				p.tex_x = texture->txtr_w - 1;
			if (p.tex_y >= texture->txtr_h)
				p.tex_y = texture->txtr_h - 1;
			tern_portal(&p);
			p.color = get_texture_pixel(texture, p.tex_x, p.tex_y);
			if (p.color != -1)
				put_pixel(all, p.screen_x, p.screen_y, p.color);
			p.screen_x++;
		}
		p.screen_y++;
	}
}

void	animate_portal(t_cub3d *data)
{
	int	frame;
	int	delay_us;

	frame = 0;
	delay_us = 80000;
	while (frame < 32)
	{
		if (!data->por_tex[frame].img)
			continue ;
		draw_portal(data, &data->por_tex[frame]);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
		mlx_do_sync(data->mlx);
		usleep(delay_us);
		frame++;
	}
}

int	tp(t_cub3d *data)
{
	animate_portal(data);
	data->player_x = data->data->orgx;
	data->player_y = data->data->orgy;
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	data->teleporting = 0;
	return (0);
}
