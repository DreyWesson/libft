/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:50:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/04 17:05:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < (int)n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < (int)n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str;
// 	const char	*str2;

// 	str = "Hello there, Venus";
// 	str2 = "Hello there, Venus";
// 	printf("%i \n", ft_strncmp(str,str2,3));
// 	return (0);
// }
