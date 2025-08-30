/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_cputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:28:52 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/06 11:48:58 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

int	hb_cputchar(char c)
{
	return (write(1, &c, 1));
}

int	hb_cputchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
