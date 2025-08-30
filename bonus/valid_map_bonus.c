/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:12:02 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/28 10:05:37 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_data(t_data **data, int fd)
{
	char	*tmp;

	(*data)->north = NULL;
	(*data)->south = NULL;
	(*data)->east = NULL;
	(*data)->weast = NULL;
	(*data)->sky = NULL;
	(*data)->ground = NULL;
	(*data)->map = NULL;
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
	tmp = get_next_line(fd, 1);
	store_the_appropriate(tmp, data);
}

int	there_is_somthing(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	double_nline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] && str[i + 1] == '\n'
				&& there_is_somthing(str, i))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid_map(char *filename, t_data **data)
{
	char	*total;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error\ncan't open the file\n"), 0);
	init_data(data, fd);
	if (!(*data)->north || !(*data)->south || !(*data)->east || !(*data)->weast
		|| !(*data)->sky || !(*data)->ground)
		return (printf("Error\nMissing data:\nit should be a vlid texture"),
			printf(" with the direction \'.xpm\' \nand the color of "),
			printf("floor and sky 'RGB'\nthe map after that\n"),
			printf("without repetition of any deriction or place\n"),
			close(fd),
			0);
	total = get_next_line(fd, 1);
	while (total)
	{
		(*data)->map = ft_strjoin((*data)->map, total);
		total = get_next_line(fd, 0);
	}
	close(fd);
	if (!validate_map((*data)->map) || double_nline((*data)->map))
		return (printf("Error\nInvalid map\n"), 0);
	return (1);
}
