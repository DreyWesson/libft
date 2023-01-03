/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:50:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/03 16:28:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && i < (int)n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str;
// 	const char	*str2;

// 	str = "Hello there, Venus";
// 	str2 = "Hellx there, Venus";
// 	printf("%i \n", ft_strncmp(str,str2,3));
// 	return (0);
// }
