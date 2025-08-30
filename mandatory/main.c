/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:48:37 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 10:35:38 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_position(t_cub3d *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (is_player_char(all->map[i][j]))
			{
				all->direction = all->map[i][j];
				all->player_x = (double)j + 0.5;
				all->player_y = (double)i + 0.5;
				all->data->orgx = j;
				all->data->orgy = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_angle(t_cub3d *all)
{
	if (all->direction == 'E')
		all->player_angle = 0;
	else if (all->direction == 'S')
		all->player_angle = M_PI / 2;
	else if (all->direction == 'W')
		all->player_angle = M_PI;
	else if (all->direction == 'N')
		all->player_angle = 3 * M_PI / 2;
}

size_t	get_maxwidth(char **map)
{
	int		i;
	size_t	max;
	size_t	width;

	i = 0;
	max = 0;
	width = 0;
	while (map[i])
	{
		width = hb_strlen(map[i]);
		if (max < width)
			max = width;
		i++;
	}
	return (max);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = yalloc(sizeof(t_data));
	if (ac != 2)
	{
		printf("Error\nUsage: ./cub3D <map filename>\n");
		ft_malloc(0, FT_CLEAR);
		return (1);
	}
	if (!parsing(av[1]))
	{
		ft_malloc(0, FT_CLEAR);
		return (1);
	}
	if (!check_valid_map(av[1], &data))
		return (ft_malloc(0, FT_CLEAR), 1);
	initialize(data);
}
