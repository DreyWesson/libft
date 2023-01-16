/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:35:45 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/16 20:04:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
// int	main(void)
// {
// 	t_list	*head;
// 	int 	ptr = 45;
// 	int		ptr2 = 42;

// 	head = ft_lstnew(&ptr);
// 	ft_lstadd_back(&head, ft_lstnew(&ptr2));
// 	printf("%i, %i\n", *(int*)head->content, *(int*)head->next->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
