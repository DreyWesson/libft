/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:14:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/04 17:10:08 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_condition(
	int first_occurrence,
	int size,
	const char *haystack,
	const char *needle)
{
	if (!(first_occurrence + size - 1 >= (ft_strlen(haystack) - 1))
		&& haystack[first_occurrence + size - 1] != needle[size - 1])
		return (1);
	else
		return (0);
}

void	ft_reset(int *first_occurrence, int *k, int *l)
{
	*l = *first_occurrence;
	*first_occurrence = 0;
	*k = 0;
}

int	ft_cmp(const char *haystack, const char *needle, int *l, int size)
{
	int	k;
	int	first_occurrence;

	k = 0;
	first_occurrence = 0;
	while (haystack[*l] != '\0')
	{
		if (haystack[*l] == needle[k] && k <= size)
		{
			k += 1;
			if (first_occurrence == 0)
				first_occurrence = *l;
			if (k == size)
				return (k);
			if (ft_condition(first_occurrence, size, &haystack[0], &needle[0]))
				ft_reset(&first_occurrence, &k, &(*l));
		}
		else
			ft_reset(&first_occurrence, &k, &(*l));
		*l += 1;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	int		i;
	int		j;
	int		l;
	char	*p;
	int		k;

	p = 0;
	i = ft_strlen(needle);
	j = ft_strlen(haystack);
	l = 0;
	if (i == 0)
		return ((char *)(haystack));
	if (i > j)
		return (p);
	k = ft_cmp(haystack, needle, &l, size);
	if (k)
		return ((char *)(&haystack[l - k + 1]));
	return (p);
}

// int	main(void)
// {
// 	char haystack[] = "mississippi";
// 	char needle[] = "issip";

// 	printf("%s", ft_strnstr(haystack, needle, 3));
// 	return (0);
// }
