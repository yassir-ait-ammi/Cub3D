/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_cputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:32:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/06 11:49:10 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

int	hb_cputstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, s + (i++), 1);
	return (i);
}

int	hb_cputstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(fd, s + (i++), 1);
	return (i);
}
