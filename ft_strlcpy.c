/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:18:39 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/28 10:59:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	unsigned int	i;
	int				src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size != 0)
	{
		size--;
		while (i < (size))
		{
			dest[i] = src[i];
			i++;
		}
		dest[size] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	char	dest;
// 	char	*src;

// 	src = "Hello there, Venus";
// 	printf("%zu \n", ft_strlcpy(&dest, &src[0], 9));
// 	printf("%s", &dest);
// 	return (0);
// }
