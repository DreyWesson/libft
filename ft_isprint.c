/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:38:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:36:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

int	ft_isprint( int c )
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%i", ft_isprint(30));
// 	return (0);
// }