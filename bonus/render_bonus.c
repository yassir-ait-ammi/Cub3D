/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:45:18 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	put_pixel(t_cub3d *data, int x, int y, unsigned int color)
{
	char	*pxl;

	if (!data || !data->img.addr)
	{
		printf("Error\n put_pixel called with invalid data or img.addr\n");
		return ;
	}
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = data->img.addr + (y * data->img.line_length + x
				* (data->img.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	grade(int color, int row)
{
	float			factor;
	unsigned int	a;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (WINDOW_WIDTH <= 1)
		return (color);
	factor = (float)row / (WINDOW_HEIGHT / 2 - 1);
	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = r + (unsigned int)((255 - r) * factor);
	g = g + (unsigned int)((255 - g) * factor);
	b = b + (unsigned int)((255 - b) * factor);
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

void	sky_floor(t_cub3d *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				put_pixel(data, x, y, grade(data->sky, y));
			else
				put_pixel(data, x, y, data->floor);
			x++;
		}
		y++;
	}
}

void	render_while(t_cub3d *data, t_render *r)
{
	r->camera_x = 2.0 * r->x / (double)WINDOW_WIDTH - 1.0;
	r->ray_angle = r->originangle + (M_PI / 6.0) * r->camera_x;
	data->player_angle = r->ray_angle;
	r->distance = dda(data);
	if (r->distance < 0)
		return ;
	else if (r->distance < 0.1)
		r->distance = 0.1;
	r->distance *= cos(r->ray_angle - r->originangle);
	r->wall_height = (int)(WINDOW_HEIGHT / r->distance);
	r->draw_start = WINDOW_HEIGHT / 2 - r->wall_height / 2;
	r->draw_end = WINDOW_HEIGHT / 2 + r->wall_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= WINDOW_HEIGHT)
		r->draw_end = WINDOW_HEIGHT - 1;
	texturi_lwall(data, r);
}

void	render(t_cub3d *data)
{
	t_render	*r;
	static int	hitside;

	mlx_clear_window(data->mlx, data->win);
	r = yalloc(sizeof(t_render));
	data->hitside = &hitside;
	sky_floor(data);
	r->x = 0;
	r->originangle = data->player_angle;
	while (r->x < WINDOW_WIDTH)
	{
		render_while(data, r);
		r->x++;
	}
	data->player_angle = r->originangle;
	draw_mini_map(data);
}
