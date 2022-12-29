/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:39 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/25 14:50:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

#endif