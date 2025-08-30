/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texcture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:58:10 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 10:33:10 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	bring_the_appropriate(char *str)
{
	int			i;
	static int	c;

	i = 0;
	c++;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == 'N' && str[i + 1] && str[i + 1] == 'O' && str[i + 2] && str[i
			+ 2] != '\n' && c == 1)
		return (0);
	if (str[i] == 'S' && str[i + 1] && str[i + 1] == 'O' && str[i + 2] && str[i
			+ 2] != '\n' && c == 2)
		return (1);
	if (str[i] == 'W' && str[i + 1] && str[i + 1] == 'E' && str[i + 2] && str[i
			+ 2] != '\n' && c == 3)
		return (2);
	if (str[i] == 'E' && str[i + 1] && str[i + 1] == 'A' && str[i + 2] && str[i
			+ 2] != '\n' && c == 4)
		return (3);
	if (str[i] == 'C' && str[i + 1] && str[i + 1] != '\n' && c == 6)
		return (4);
	if (str[i] == 'F' && str[i + 1] && str[i + 1] != '\n' && c == 5)
		return (5);
	printf("Error\nInvalid order\n1 NO\n2 SO\n3 WE\n4 EA\n5 F\n6 C\n");
	return (ft_exit(1), -1);
}

void	store_the_appropriate(char *str, t_data **data)
{
	int	index;

	index = bring_the_appropriate(str);
	if (index == 0)
		(*data)->north = str + 3;
	else if (index == 1)
		(*data)->south = str + 3;
	else if (index == 2)
		(*data)->weast = str + 3;
	else if (index == 3)
		(*data)->east = str + 3;
	else if (index == 4)
		(*data)->sky = str + 2;
	else if (index == 5)
		(*data)->ground = str + 2;
	else
	{
		(*data)->north = NULL;
		(*data)->south = NULL;
		(*data)->east = NULL;
		(*data)->weast = NULL;
		(*data)->sky = NULL;
		(*data)->ground = NULL;
	}
}
