/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:29:34 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/13 19:32:34 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

void	*hb_realloc(void *ptr, size_t size)
{
	void	*newblock;

	if (ptr == NULL)
		return (yalloc(size));
	if (size == 0)
		return (free(ptr), NULL);
	newblock = yalloc(size);
	if (!newblock)
		return (NULL);
	hb_memcpy(newblock, ptr, size);
	free(ptr);
	return (newblock);
}
