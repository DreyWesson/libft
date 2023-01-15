/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:03:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/15 19:44:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	head->content = content;
	head->next = NULL;
	return (head);
}
// int main(void)
// {
// 	int	ptr;

// 	ptr = 45;
// 	ft_lstnew(&ptr);
// 	return (0);
// }
