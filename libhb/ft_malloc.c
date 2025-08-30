/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:51:54 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/26 11:28:36 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhb.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*one;
	t_list	*two;

	if (!lst || !del)
		return ;
	one = *lst;
	while (one != NULL)
	{
		two = one->next;
		del(one->content);
		free(one);
		one = two;
	}
	*lst = NULL;
}

t_list	*mem_alloc(size_t size)
{
	t_list	*new;
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_malloc(0, FT_CLEAR);
		free(ptr);
		return (NULL);
	}
	new = hb_lstnew(ptr);
	if (!new)
	{
		ft_malloc(0, FT_CLEAR);
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
		new = mem_alloc(size);
		if (!new)
		{
			ft_lstclear(&head, free);
			printf("Error\nMemory allocation failed\n");
			exit(1);
		}
		hb_lstadd_back(&head, new);
		return (new->content);
	}
	if (option == FT_CLEAR)
		ft_lstclear(&head, free);
	return (NULL);
}

void	*yalloc(size_t size)
{
	return (ft_malloc (size, 1));
}

void	yfree(void)
{
	ft_malloc(0, 0);
}
