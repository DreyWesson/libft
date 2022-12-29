/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:29:04 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/23 10:15:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			p = &s[i];
		i++;
	}
	return (p);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello there, lVenus";
// 	printf("%s \n", ft_strchr(&str[0], 'l'));
// 	return (0);
// }