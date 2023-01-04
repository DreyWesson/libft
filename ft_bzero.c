/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:05:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/04 16:37:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (s == NULL)
		return ;
	while ((int)n-- >= 0)
		*(unsigned char *)(s + n) = 0;
}

// int	main(void)
// {
// 	int arr[2] = {1,2};

// 	ft_bzero(arr, 2 * sizeof(int));
// 	for (int i =0; i < 2; i++)
//     	printf("%i\n", arr[i]);
// 	return (0);
// }