/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:32 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/23 09:46:36 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readline(int fd, char *string, char *buff)
{
	ssize_t	cont;
	char	*fnl;

	cont = 0;
	fnl = NULL;
	while (!fnl)
	{
		cont = read(fd, buff, BUFFER_SIZE);
		if (!cont)
			break ;
		if (cont < 0)
			return (NULL);
		buff[cont] = '\0';
		fnl = ft_strchr(buff, '\n');
		string = ft_strjoin(string, buff);
	}
	return (string);
}

static void	ft_getline(char **string, char **line)
{
	size_t	i;

	if (!**string)
	{
		*string = NULL;
		*line = NULL;
		return ;
	}
	i = 0;
	while ((*string)[i] && (*string)[i] != '\n')
		i++;
	if (!(*string)[i])
	{
		*line = ft_strdup(*string);
		return ;
	}
	*line = ft_substr(*string, i + 1);
	*string = ft_strdup(&(*string)[i + 1]);
}

char	*get_next_line(int fd, int flax)
{
	char		*buff;
	static char	*string;
	char		*line;

	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(string, '\n'))
	{
		buff = yalloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		string = ft_readline(fd, string, buff);
		if (!string)
			return (NULL);
	}
	ft_getline(&string, &line);
	if (line && line[0] == '\n' && flax == 1)
		return (get_next_line(fd, flax));
	return (line);
}
