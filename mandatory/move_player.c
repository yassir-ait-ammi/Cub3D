/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:06:54 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 15:33:41 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	move_player(t_cub3d *data, double newx, double newy)
{
	if (can_move(data, newx, data->player_y))
		data->player_x = newx;
	if (can_move(data, data->player_x, newy))
		data->player_y = newy;
}
