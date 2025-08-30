/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:17:15 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 10:12:26 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	pars_the_name(char *str)
{
	int	i;

	i = hb_strlen(str);
	i--;
	if (str[i] != 'b')
		return (0);
	i--;
	if (str[i] != 'u')
		return (0);
	i--;
	if (str[i] != 'c')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	return (1);
}

int	check_characrter(char *str)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] && a < 6)
	{
		if (str[i] != '\n' && str[i + 1] == '\n')
			a++;
		i++;
	}
	if (a != 6)
		return (0);
	while (str[i] && a == 6)
	{
		if (!is_required(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(char *filename)
{
	int		fd;
	char	content[2];
	char	*total;
	int		i;

	if (!pars_the_name(filename))
		return (printf("Error\ninvalid file name\n"), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error\ncan't open the file\n"), 0);
	i = read(fd, content, 1);
	total = hb_strdup("");
	while (i != 0)
	{
		content[1] = '\0';
		total = ft_strjoin(total, content);
		i = read(fd, content, 1);
	}
	close(fd);
	if (!total[0])
		return (printf("Error\nempty map\n"), 0);
	if (!check_characrter(total))
		return (printf("Error\ninvalid char inside the map\n"), 0);
	return (1);
}
