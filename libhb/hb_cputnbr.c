/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_cputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:25 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/06 11:48:46 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

int	hb_cputnbr(int n)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		cont += hb_cputchar('-');
	}
	if (n < 10)
		cont += hb_cputchar('0' + n);
	else
	{
		cont += hb_cputnbr(n / 10);
		cont += hb_cputnbr(n % 10);
	}
	return (cont);
}

int	hb_cputnbr_fd(int n, int fd)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		cont += hb_cputchar_fd('-', fd);
	}
	if (n < 10)
		cont += hb_cputchar_fd('0' + n, fd);
	else
	{
		cont += hb_cputnbr_fd(n / 10, fd);
		cont += hb_cputnbr_fd(n % 10, fd);
	}
	return (cont);
}
