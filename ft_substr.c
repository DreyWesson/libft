/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:08:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/15 16:27:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	if (!len || start >= (ft_strlen(s)))
		return (ft_strdup(""));
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (ptr == 0)
		return (NULL);
	end = start + len;
	i = 0;
	while (start < end)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("hola", 2, 2));
// 	return (0);
// }
