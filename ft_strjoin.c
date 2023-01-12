/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:54:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/11 17:02:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_len;
	int		len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	len = ft_strlen(s2) + s1_len + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	s1_len = 0;
	while (s1_len < len)
	{
		ptr[i] = s2[s1_len];
		s1_len++;
		i++;
	}
	ptr[s1_len] = '\0';
	return ((char *)(ptr));
}

// int main(void)
// {
// 	printf("%s\n", ft_strjoin("Drey","Oduwole"));
// 	return (0);
// }