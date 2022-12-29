/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:54:41 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/24 20:22:59 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;
	int		capacity;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	capacity = s1_len + s2_len;
	ptr = malloc(capacity);
	if (!ptr)
		return (NULL);
	while (i < s1_len)
	{
		*(ptr + i) = s1[i];
		i++;
	}
	while (i < capacity)
	{
		*(ptr + i) = s2[i - s1_len];
		i++;
	}
	return ((char *)(ptr));
}

// int main(void)
// {
// 	printf("%s\n", ft_strjoin("Drey","Oduwole"));
// 	return (0);
// }