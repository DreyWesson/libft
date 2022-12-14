/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:18:39 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/13 09:03:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
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
// 	printf("%i \n", ft_strlcpy(&dest, &src[0], 9));
// 	printf("%s", &dest);
// 	return (0);
// }
