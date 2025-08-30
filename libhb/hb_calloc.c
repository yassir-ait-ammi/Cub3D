/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:08:55 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/13 16:55:28 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

void	*hb_calloc(size_t len, size_t b)
{
	void	*p;

	if (b && len > SIZE_MAX / b)
		return (NULL);
	p = yalloc(len * b);
	if (!p)
		return (NULL);
	hb_bzero(p, len * b);
	return (p);
}
