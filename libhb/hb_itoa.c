/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:18:48 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/13 16:55:28 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

static int	hb_lenum(int n, int nega)
{
	int	l;

	l = 1;
	if (nega)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		l++;
	}
	if (nega)
		return (l + 1);
	return (l);
}

static int	hb_nega(int n, char *num)
{
	*num = '-';
	n *= -1;
	return (n);
}

char	*hb_itoa(int n)
{
	char	*num;
	int		nega;
	int		lenum;

	num = NULL;
	if (n == -2147483648)
		return (hb_strdup("-2147483648"));
	nega = (n < 0);
	lenum = hb_lenum (n, nega);
	num = yalloc(lenum + 1);
	if (!num)
		return (NULL);
	if (nega)
		n = hb_nega(n, num);
	num[lenum--] = '\0';
	while (0 <= lenum)
	{
		if (nega && !lenum)
			break ;
		num[lenum--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
