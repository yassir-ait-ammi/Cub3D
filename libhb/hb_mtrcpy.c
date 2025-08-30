/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_mtrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:12:33 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/13 19:31:34 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

char	**hb_mtrcpy(char **mtr)
{
	char	**m;
	size_t	i;

	m = (char **)yalloc(hb_mtrlen(mtr) * (sizeof(char *) + 2));
	if (!m)
		return (NULL);
	i = 0;
	while (mtr[i])
	{
		m[i] = hb_strdup(mtr[i]);
		i++;
	}
	m[i] = NULL;
	return (m);
}
