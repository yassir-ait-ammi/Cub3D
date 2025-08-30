/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:05:45 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/21 16:38:53 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

int	hb_atoi(const char *nbr)
{
	int	n;
	int	s;

	s = 1;
	n = 0;
	while (!hb_isdigit(*nbr) && *nbr != '-' && *nbr != '+')
	{
		if ((9 <= *nbr && *nbr <= 13) || *nbr == 32)
			nbr++;
		else
			return (0);
	}
	if (*nbr == '-' || *nbr == '+')
		if (*(nbr++) == '-')
			s = -1;
	while (hb_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	if (*nbr && *nbr != '\n')
		return (-1337);
	return (n * s);
}
