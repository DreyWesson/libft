/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:10:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/11 12:07:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
	// char	*ptr;
	// size_t	i;

	// ptr = ft_strdup(s);
	// if (!ptr)
	// 	return (NULL);
	// i = 0;
	// while (ptr[i])
	// {
	// 	ptr[i] = (*f)(i, ptr[i]);
	// 	i++;
	// }
	// return (ptr);

// char	f(unsigned int i, char c)
// {
// 	printf("%c\t%i\n", c, i);
// 	return (c);
// }

// int	main(void)
// {
// 	ft_strmapi("Drey", f);
// 	return (0);
// }