/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:39:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 12:18:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Iterates the list ’lst’
// applies the function ’f’ on the content of each node.
// Creates a new list from the return value of function ’f’. 
// The ’del’ function is used to delete the content of a node if needed.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current_node;

	if (!f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		current_node = ft_lstnew((*f)(lst->content));
		if (!current_node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, current_node);
		lst = lst->next;
	}
	return (result);
}
