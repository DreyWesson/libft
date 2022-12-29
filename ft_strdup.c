/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:01:17 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/24 20:23:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

char	*strdup(const char *s1);

char	*strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(len);
	while (i < len)
	{
		*(ptr + i) = s1[i];
		i++;
	}
	return ((char *)(ptr));
}

// int	main(void)
// {
// 	char s1[] = "Drey";
// 	printf("%s\n",strdup(s1));
// 	return (0);
// }
