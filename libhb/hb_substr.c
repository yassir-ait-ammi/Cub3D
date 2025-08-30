/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:50:37 by habenydi          #+#    #+#             */
/*   Updated: 2025/07/13 16:55:28 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

char	*hb_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (len + start >= hb_strlen(s))
		len = hb_strlen(s) - start;
	if (start >= hb_strlen(s))
		return (hb_strdup(""));
	subs = yalloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
