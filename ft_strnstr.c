/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:14:21 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/14 11:01:45 by doduwole         ###   ########.fr       */
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

// when you see the first occurrence check if the value on the last occurrence is same


void	ft_cmp(char *haystack, char *needle, int *k, int *l)
{	
	int	i;
	int first_occurrence;

	first_occurrence = 0;
	i = ft_str_len(needle);
	while (haystack[*l] != '\0')
	{
		if (haystack[*l] == needle[*k] && *k <= i)
		{
			if (first_occurrence == 0)
				first_occurrence = *l;
			*k += 1;
			if (*k == i)
				break ;
		printf("%i %i %c %c\n",first_occurrence, first_occurrence + i - 1, haystack[first_occurrence + i -1],needle[i-1]);
			if (!(first_occurrence + i - 1 > ft_str_len(haystack))
				&& haystack[first_occurrence + i - 1] != needle[i - 1])
			{
				first_occurrence = 0;
				*k = 0;
				*l += 1;
				continue ;
			}
		}
		else
			*k = 0;

		*l += 1;
	}

}

char	*ft_strnstr(char *haystack, char *needle)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*p;

	p = 0;
	i = ft_str_len(needle);
	j = ft_str_len(haystack);
	k = 0;
	l = 0;
	if (i == 0)
		return (haystack);
	if (i > j)
		return (p);
	ft_cmp(haystack, needle, &k, &l);
	if (k == i)
	{
		p = &haystack[l - k + 1];
		return (p);
	}
	return (p);
}

#include <stdio.h>
int main(void)
{
	char haystack[] = "mississippi";
	char needle[] = "issip";
	printf("%s",ft_strnstr(haystack, needle));
	return (0);
}