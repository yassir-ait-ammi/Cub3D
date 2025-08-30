/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:58:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

ssize_t	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	if (!texture || !texture->addr || x < 0 || y < 0)
		return (-1);
	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	render_y(t_cub3d *data, t_render *r, t_img *texture, int tex_x)
{
	int	y;
	int	tex_y;
	int	d;
	int	color;

	y = r->draw_start;
	while (y <= r->draw_end)
	{
		d = y * 256 - WINDOW_HEIGHT * 128 + r->wall_height * 128;
		tex_y = ((d * texture->txtr_h) / r->wall_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->txtr_h)
			tex_y = texture->txtr_h - 1;
		color = get_texture_pixel(texture, tex_x, tex_y);
		if (color != -1)
			put_pixel(data, r->x, y, color);
		y++;
	}
}

void	texturi_lwall(t_cub3d *data, t_render *r)
{
	t_img	*texture;
	int		tex_x;

	if (data->hitype)
		texture = &data->dor_tex;
	else if (*data->hitside == 0)
	{
		if (data->ray_dir_x > 0)
			texture = &data->ea_texture;
		else
			texture = &data->we_tex;
	}
	else
	{
		if (data->ray_dir_y > 0)
			texture = &data->so_texture;
		else
			texture = &data->no_texture;
	}
	tex_x = (int)(data->wall * texture->txtr_w);
	render_y(data, r, texture, tex_x);
}
