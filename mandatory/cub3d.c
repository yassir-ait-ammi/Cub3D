/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:54:42 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/23 10:34:34 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	create_color(char *str)
{
	char	**color;
	int		red;
	int		green;
	int		blue;
	int		i;

	color = hb_split(str, ',');
	i = 0;
	while (color[i])
		i++;
	if (i < 3 || i > 3)
		return (-1337);
	red = hb_atoi(color[0]);
	green = hb_atoi(color[1]);
	blue = hb_atoi(color[2]);
	if (red < 0 || green < 0 || blue < 0 || red > 255 || green > 255
		|| blue > 255)
		return (-1337);
	return (red << 16 | green << 8 | blue);
}

void	init_color(t_data *data, t_cub3d *all)
{
	all->sky = create_color(data->sky);
	all->floor = create_color(data->ground);
	if (all->sky < 0 || all->floor < 0)
	{
		printf("Error\nthe color RGB sholud be all ");
		printf("positive less than 255 and with no char\n");
		ft_exit(1);
	}
}

t_cub3d	*init_data_for_simulation(t_data *data)
{
	t_cub3d	*all;

	all = yalloc(sizeof(t_cub3d));
	hb_bzero(all, sizeof(t_cub3d));
	init_color(data, all);
	return (all);
}
