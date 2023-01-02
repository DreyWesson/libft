/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:37:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 12:15:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}
// int	main(void)
// {
// 	ft_putnbr_fd(1234, 1);
// 	return (0);
// }
