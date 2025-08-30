/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_mini_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:09:53 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	put_pixel_for_mini(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MINI || y < 0 || y >= MINI)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_cub3d *all, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_for_mini(&all->img, x + j, y + i, all->color_cub);
			j++;
		}
		i++;
	}
}

void	ternaries(int a, int b, int *x)
{
	if (a < b)
		*x = 1;
	else
		*x = -1;
}
