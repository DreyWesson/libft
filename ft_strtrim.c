/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:24:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:42:40 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_str_trim(char const *s1, char const *set);
int		ft_trim_head(char const *s1, char const *set);
int		ft_trim_tail(char const *s1, char const *set);

int	ft_trim_tail(char const *s1, char const *set)
{
	int	tail;
	int	head;

	head = ft_strlen(s1) - 1;
	tail = 0;
	while (tail < head)
	{
		if ((*(char *)(s1 + tail)) != (*(char *)(set)))
			break ;
		tail++;
	}
	return (tail);
}

int	ft_trim_head(char const *s1, char const *set)
{
	int	head;

	head = ft_strlen(s1) - 1;
	while (head > 0)
	{
		if ((*(char *)(s1 + head)) != (*(char *)(set)))
			break ;
		head--;
	}
	return (head);
}

char	*ft_str_trim(char const *s1, char const *set)
{
	int		tail;
	int		head;
	char	*ptr;
	int		i;

	i = 0;
	tail = ft_trim_tail(s1, set);
	head = ft_trim_head(s1, set);
	ptr = malloc(head - tail);
	if (!ptr)
		return (NULL);
	while (tail <= head)
	{
		*(ptr + i) = s1[tail];
		i++;
		tail++;
	}
	return (ptr);
}
// int	main(void)
// {
// 	ft_strtrim("   Hello world!    ", " ");
// 	return (0);
// }
