/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:01:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/11 12:08:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)(ptr));
}

// int	main(void)
// {
// 	char s1[] = "Drey";
// 	ft_strdup(s1);
// 	// printf("%s\n",ft_strdup(s1));
// 	return (0);
// }
