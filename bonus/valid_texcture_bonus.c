/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texcture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:58:10 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/28 15:28:13 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	bring_the_appropriate(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == 'N' && str[i + 1] && str[i + 1] == 'O' && str[i + 2] && str[i
			+ 2] != '\n')
		return (0);
	if (str[i] == 'S' && str[i + 1] && str[i + 1] == 'O' && str[i + 2] && str[i
			+ 2] != '\n')
		return (1);
	if (str[i] == 'W' && str[i + 1] && str[i + 1] == 'E' && str[i + 2] && str[i
			+ 2] != '\n')
		return (2);
	if (str[i] == 'E' && str[i + 1] && str[i + 1] == 'A' && str[i + 2] && str[i
			+ 2] != '\n')
		return (3);
	if (str[i] == 'C' && str[i + 1] && str[i + 1] != '\n')
		return (4);
	if (str[i] == 'F' && str[i + 1] && str[i + 1] != '\n')
		return (5);
	return (-1);
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
