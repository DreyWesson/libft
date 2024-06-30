/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:05:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/15 16:44:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

// int	main(void)
// {
// 	int arr[2] = {1,2};

// 	ft_bzero(arr, 2 * sizeof(int));
// 	for (int i =0; i < 2; i++)
//     	printf("%i\n", arr[i]);
// 	return (0);
// }