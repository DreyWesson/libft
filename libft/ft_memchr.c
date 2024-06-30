/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:13:10 by doduwole          #+#    #+#             */
/*   Updated: 2024/06/29 14:50:05 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s + i)) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char src[] = "Copy that";
// 	char c = 'p';
// 	// int src[5] = {1, 2, 3, 4, 5};
// 	// int c = 3;
// 	printf("%p\n", ft_memchr(src, c, sizeof(int) * 5));
// 	return (0);
// }
