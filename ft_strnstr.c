/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:14:21 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/14 12:30:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int	ft_cmp(char *haystack, char *needle, int *l, int size)
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
			if (!(first_occurrence + size - 1 >= (ft_str_len(haystack) - 1))
				&& haystack[first_occurrence + size - 1] != needle[size - 1])
			{
				first_occurrence = 0;
				k = 0;
				*l += 1;
				continue ;
			}
		}
		else
			k = 0;
		*l += 1;
	}
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle, int size)
{
	int		i;
	int		j;
	int		l;
	char	*p;
	int		k;

	p = 0;
	i = ft_str_len(needle);
	j = ft_str_len(haystack);
	l = 0;
	if (i == 0)
		return (haystack);
	if (i > j)
		return (p);
	k = ft_cmp(haystack, needle, &l, size);
	if (k)
		return (&haystack[l - k + 1]);
	return (p);
}

int main(void)
{
	char haystack[] = "mississippi";
	char needle[] = "issfsissip";

	printf("%s", ft_strnstr(haystack, needle, 3));
	return (0);
}
