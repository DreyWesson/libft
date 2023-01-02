/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:10:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:42:00 by doduwole         ###   ########.fr       */
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
	if (s == NULL || f == NULL)
		return (NULL);
	ptr = malloc(ft_strlen(s));
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}

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