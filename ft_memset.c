/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:47:49 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:38:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	*ft_memset(void *s, int n, size_t len);

void	*ft_memset(void *s, int n, size_t len)
{
	if (s == NULL)
		return (NULL);
	while (--len >= 0)
	{
		*(unsigned char *)(s + len) = n;
		if (len == 0)
			break ;
	}
	return (s);
}

// int	main(void)
// {
// 	int arr[2] = {1,2};

// 	ft_memset(arr,28, 8);
// 	for (int i =0; i < 2; i++)
//     	printf("%i\n", arr[i]);
// 	return (0);
// }