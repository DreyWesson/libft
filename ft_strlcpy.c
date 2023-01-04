/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:18:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/04 08:27:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	dest;

// 	printf("%zu \n", ft_strlcpy(&dest, "", 15));
// 	printf("%s\n", &dest);
// 	return (0);
// }
