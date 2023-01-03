/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:29:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/03 14:21:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = 0;
	p = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			p = &s[i];
		i++;
	}
	return ((char *)p);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello there, lVenus";
// 	printf("%s \n", ft_strchr(&str[0], 'l'));
// 	return (0);
// }