/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/02 10:45:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif