/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:08:41 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/24 20:24:23 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	int		size;

	i = 0;
	size = start + len;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (start < (unsigned int)size)
	{
		*(ptr + i) = s[start];
		start++;
		i++;
	}
	printf("%s\n", ((char *)ptr));
	return ((char *)ptr);
}

// int main(void)
// {
// 	ft_substr("Drey", 1, 2);
// 	return (0);
// }