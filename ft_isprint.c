/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:38:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/03 19:18:22 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isprint( int c )
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int i = 123;
//     while (i <= 127)
//     {
// 		printf("%i", ft_isprint(i));
//         i++;
//     }
// 	return (0);
// }