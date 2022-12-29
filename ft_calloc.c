/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:40:47 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/23 20:27:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;
	int	capacity;
	int	i;

	i = 0;
	capacity = count * size;
	p = (int *)malloc(capacity);
	while (i < capacity)
	{
		*(p + i) = 0;
		i++;
	}
	return (p);
}

// int main(void)
// {
// 	ft_calloc(8, sizeof(int));
// 	return (0);
// }