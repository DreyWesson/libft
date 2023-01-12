/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:27:22 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/12 11:13:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c);

char	**ft_mem_allocator(const char *s, char c)
{
	int		itr;
	int		delimiter_counter;
	char	**ptr;

	itr = 0;
	delimiter_counter = 0;
	while (s[itr] != '\0')
	{
		if (s[itr] == c)
			delimiter_counter++;
		itr++;
	}
	ptr = malloc(delimiter_counter + 2);
	if (!ptr)
		return (NULL);
	return (ptr);
}

void	ft_substr_allocator(char **ptr, int *delimiter_counter, char *buffer)
{
	ptr[*delimiter_counter] = malloc(ft_strlen(buffer) + 1);
	ft_memcpy(ptr[*delimiter_counter], buffer, (size_t)ft_strlen(buffer) + 1);
}

void	ft_copy_substr(char *buffer, const char *s, int *substr_idx, int *itr)
{
		buffer[*substr_idx] = s[*itr];
		*substr_idx += 1;
}

void	ft_reset(int *delimiter_counter, int *substr_idx)
{
	*delimiter_counter += 1;
	*substr_idx = 0;
}

char	**ft_split(char const *s, char c)
{
	int		itr;
	int		delimiter_counter;
	int		substr_idx;
	char	**ptr;
	char	buffer[16384];

	itr = 0;
	substr_idx = 0;
	delimiter_counter = 0;
	ptr = ft_mem_allocator(s, c);
	if (!ptr)
		return (NULL);
	while (s[itr] != '\0')
	{
		buffer[substr_idx] = '\0';
		ft_substr_allocator(ptr, &delimiter_counter, buffer);
		if (s[itr] == c)
		{
			if (itr != 0)
				ft_reset(&delimiter_counter, &substr_idx);
		}
		else
			ft_copy_substr(buffer, s, &substr_idx, &itr);
		itr++;
	}
	ptr[delimiter_counter] = NULL;
	return (ptr);
}

int	main(void)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (ptr[i] != NULL)
	{
		printf("%s\n", *(ptr + i));
		i++;
	}
	return (0);
}
