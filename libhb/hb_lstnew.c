/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:55:57 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/21 16:41:26 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

t_list	*hb_lstnew(void *content)
{
	t_list	*yas;

	yas = malloc(sizeof(t_list));
	if (!yas)
		return (NULL);
	yas->content = content;
	yas->next = NULL;
	return (yas);
}
