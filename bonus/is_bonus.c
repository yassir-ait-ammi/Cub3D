/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:18:26 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_required(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == '\t' || c == 'E'
		|| c == 'D' || c == 'S' || c == 'P' || c == 'W' || c == '\n'
		|| c == ' ');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_valide(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_invalid_border(char **map, int x, int y, int rows)
{
	if (y < 0 || x < 0 || y >= rows || x >= (int)hb_strlen(map[y]))
		return (1);
	if (map[y][x] == ' ')
		return (1);
	return (0);
}
