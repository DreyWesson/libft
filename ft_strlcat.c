/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:32:59 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/13 09:02:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	j = 0;
	k = ft_str_len(src);
	i = ft_str_len(dest);
	if (size == 0)
		return (k);
	if (size <= i)
		return (size + k);
	while (src[j] != '\0')
	{
		if ((size - 1) == (j + i))
			break ;
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + k);
}

// int	main(void)
// {
// 	char	*s;
//     char	target[128] = "target buffer#";
// 	s = "hello duplicates";
//     printf("Hello World: \"%s\"\n", target);
//     ft_strlcat(target, s, 128);
//     printf("New target: \"%s\"\n", target);
//     return (0);
// }
