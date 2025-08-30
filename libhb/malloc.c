/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:46:02 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/26 11:29:07 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

t_list	*mem_malloc(size_t size)
{
	t_list	*new;
	void	*ptr;

	ptr = mft_malloc(size);
	if (!ptr)
	{
		ft_mft_malloc(0, FT_CLEAR);
		free(ptr);
		return (NULL);
	}
	new = ft_lstnew(ptr);
	if (!new)
	{
		ft_mft_malloc(0, FT_CLEAR);
		free(ptr);
		return (NULL);
	}
	return (new);
}

void	*ft_malloc(size_t size, short option)
{
	static t_list	*head;
	t_list			*new;

	if (option == FT_ALLOC)
	{
		new = mem_malloc(size);
		if (!new)
		{
			ft_lstclear(&head, free);
			printf("Error\nMemory ft_mallocation failed\n");
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		return (new->content);
	}
	if (option == FT_CLEAR)
		ft_lstclear(&head, free);
	return (NULL);
}
