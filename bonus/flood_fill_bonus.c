/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:10:06 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 10:11:50 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	check_surround(char **map, int rows)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (map[y][x])
		{
			if (is_valide(map[y][x]))
			{
				if (
					is_invalid_border(map, x + 1, y, rows)
					|| is_invalid_border(map, x - 1, y, rows)
					|| is_invalid_border(map, x, y + 1, rows)
					|| is_invalid_border(map, x, y - 1, rows))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	flood_fill(char **map, int x, int y, int rows)
{
	if (y < 0 || x < 0 || y >= rows || x >= (int)hb_strlen(map[y]))
		return (0);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	map[y][x] = 'X';
	return (flood_fill(map, x + 1, y, rows) && flood_fill(map, x - 1, y, rows)
		&& flood_fill(map, x, y + 1, rows) && flood_fill(map, x, y - 1, rows));
}

void	find_the_point(int rows, char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows && (*y) == -1)
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valide(map[i][j]))
			{
				(*x) = j;
				(*y) = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	is_only_required(char *input)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == 'N' || input[i] == 'E' || input[i] == 'S'
			|| input[i] == 'W')
			nb++;
		i++;
	}
	if (nb > 1 || nb == 0)
	{
		printf("Erorr\nits should only one char that give ");
		printf("where the player should look in first\n");
		return (0);
	}
	return (1);
}

int	validate_map(char *input)
{
	char	**map;
	int		x;
	int		y;
	int		rows;

	x = -1;
	y = -1;
	rows = 0;
	map = hb_split(input, '\n');
	if (!map || !map[0])
		return (0);
	while (map[rows])
		rows++;
	find_the_point(rows, map, &x, &y);
	if (x == -1 || y == -1 || !check_surround(map, rows) || !flood_fill(map, x,
			y, rows))
		return (0);
	if (!is_only_required(input))
		ft_exit(1);
	return (1);
}
