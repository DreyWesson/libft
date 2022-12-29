/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:14:45 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/23 14:38:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello there, Venus";
// 	printf("%p \n", ft_strchr(&str[0], 'l'));
// 	return (0);
// }
