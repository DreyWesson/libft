/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:17:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:37:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s1 + i)) != (*(unsigned char *)(s2 + i)))
			return ((*(char *)(s1 + i)) - (*(char *)(s2 + i)));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int arr1[5] = {9,2,3,4,5};
// 	int arr2[5] = {1,2,3,4,5};
	// char arr1[] = "abc";
	// char arr2[] = "abd";
	// ft_memcmp(arr1, arr2, 3);
// 	printf("%d\n", ft_memcmp(arr1, arr2, sizeof(int)*5));
// 	return (0);
// }