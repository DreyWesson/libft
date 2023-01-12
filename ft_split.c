/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:27:22 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/12 08:54:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c);
int		ft_delimiter_counter(const char *s, char c);
void	ft_substr_allocator(char **ptr, int *delimiter_counter, char *buffer);
void	ft_reset(int *delimiter_counter, int *substr_idx);

int	ft_delimiter_counter(const char *s, char c)
{
	int		itr;
	int		delimiter_counter;

	itr = 0;
	delimiter_counter = 0;
	while (s[itr] != '\0')
	{
		if (s[itr] == c)
			delimiter_counter++;
		itr++;
	}
	return (delimiter_counter);
}

void	ft_substr_allocator(char **ptr, int *delimiter_counter, char *buffer)
{
	ptr[*delimiter_counter] = malloc(ft_strlen(buffer) + 1);
	ft_memcpy(ptr[*delimiter_counter], buffer, (size_t)ft_strlen(buffer) + 1);
}

void	ft_copy_substr(char *buffer, const char *s, int *substr_idx, int *itr)
{
		buffer[*substr_idx] = s[*itr];
		*substr_idx = *substr_idx + 1;
}

void	ft_reset(int *delimiter_counter, int *substr_idx)
{
	*delimiter_counter = *delimiter_counter + 1;
	*substr_idx = 0;
}

char	**ft_split(char const *s, char c)
{
	int		itr;
	int		delimiter_counter;
	int		substr_idx;
	char	**ptr;
	char	buffer[16384];

	itr = -1;
	substr_idx = 0;
	ptr = malloc(ft_delimiter_counter(s, c));
	while (s[itr++] != '\0')
	{
		if (s[itr] == c)
		{
			if (itr == 0)
				continue ;
			buffer[substr_idx] = '\0';
			ft_substr_allocator(ptr, &delimiter_counter, buffer);
			ft_reset(&delimiter_counter, &substr_idx);
			continue ;
		}
		ft_substr_allocator(ptr, &delimiter_counter, buffer);
		ft_copy_substr(buffer, s, &substr_idx, &itr);
	}
	ptr[delimiter_counter] = NULL;
	return (ptr);
}

int	main(void)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = ft_split("mississippi", 'i');
	while (ptr[i] != NULL)
	{
		printf("%s\n", *(ptr + i));
		i++;
	}
	return (0);
}
