/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:40 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 18:45:07 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_line(t_cub3d *all, int x1, int y1, int color)
{
	t_line	line;

	line.dx = abs(x1 - 48);
	line.dy = abs(y1 - 48);
	ternaries(48, x1, &line.sx);
	ternaries(48, y1, &line.sy);
	line.err = line.dx - line.dy;
	(1) && (line.x = 48), (line.y = 48);
	while (1)
	{
		put_pixel_for_mini(&all->img, line.x, line.y, color);
		if (line.x == x1 && line.y == y1)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			line.y += line.sy;
		}
	}
}

void	draw_player_direction(t_cub3d *all, int color)
{
	double	dir_x;
	double	dir_y;
	int		end_x;
	int		end_y;

	dir_x = cos(all->player_angle);
	dir_y = sin(all->player_angle);
	end_x = 48 + (int)(dir_x * 10);
	end_y = 48 + (int)(dir_y * 10);
	draw_line(all, end_x, end_y, color);
}

int	chosse_color(char c)
{
	if (c == '1')
		return (0x000000);
	else if (c == 'D')
		return (0x0000ff);
	else if (c == 'O')
		return (0x00ff00);
	else if (c == '0')
		return (0xFFFFFF);
	else
		return (0x808080);
}

void	draw_square_inside(t_cub3d *all, t_line *m)
{
	m->j = all->player_x - VIEW_RANGE;
	while (m->j <= all->player_x + VIEW_RANGE)
	{
		m->dx = (m->j - all->player_x) * MINI_TILE;
		m->dy = (m->i - all->player_y) * MINI_TILE;
		if (m->dx * m->dx + m->dy * m->dy > m->r * m->r || m->i < 0 || m->j < 0
			|| !all->map[m->i] || m->j >= (int)hb_strlen(all->map[m->i]))
		{
			m->j++;
			continue ;
		}
		if ((int)all->data->orgx == m->j && (int)all->data->orgy == m->i)
			all->color_cub = 0x6c00d6;
		else
			all->color_cub = chosse_color(all->map[m->i][m->j]);
		if (all->color_cub == 0x808080)
		{
			m->j++;
			continue ;
		}
		draw_square(all,
			(m->j - all->player_x + 5) * 10,
			(m->i - all->player_y + 5) * 10, 10 - 2);
		m->j++;
	}
}

void	draw_mini_map(t_cub3d *all)
{
	t_line	m;

	m.i = all->player_y - VIEW_RANGE;
	m.r = VIEW_RANGE * MINI_TILE;
	if (m.i < 0)
		m.i = 0;
	if (m.i > (int)all->data->ymax)
		m.i = all->data->ymax;
	while (m.i <= all->player_y + VIEW_RANGE)
	{
		draw_square_inside(all, &m);
		if (m.i >= (int)all->data->ymax)
			break ;
		m.i++;
	}
	all->color_cub = 0xff0000;
	draw_square(all, 45, 45, 7);
	draw_player_direction(all, 0x000000);
}
