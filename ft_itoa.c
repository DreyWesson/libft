/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:13:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/03 16:18:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_handle_zero(char *ptr, int *itr)
{
	ptr[*itr] = '0';
	*itr = *itr + 1;
	ptr[*itr] = '\0';
	return (ptr);
}

int	ft_is_neg(int *n)
{
	int		is_negative;

	is_negative = 0;
	if (*n < 0)
		is_negative = 1;
	return (is_negative);
}

void	ft_str_converter(char *ptr, int *n, int *itr)
{
	int	rem;

	rem = 0;
	while (*n != 0)
	{
		rem = *n % 10;
		*n = *n / 10;
		if (rem < 0)
			rem = -rem;
		if (rem > 9)
			ptr[*itr] = (rem - 10) + 'a';
		else
			ptr[*itr] = rem + '0';
		*itr = *itr + 1;
	}
}

char	*ft_reverse_str(char *ptr, int itr)
{
	char	tmp;
	int		tail;

	tail = 0;
	itr--;
	while (tail < itr)
	{
		tmp = ptr[itr];
		ptr[itr] = ptr[tail];
		ptr[tail] = tmp;
		itr--;
		tail++;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		itr;
	int		is_negative;

	ptr = malloc(256);
	if (!ptr)
		return (NULL);
	itr = 0;
	is_negative = ft_is_neg(&n);
	if (n == 0)
		return (ft_handle_zero(ptr, &itr));
	if (is_negative)
		n = -n;
	ft_str_converter(ptr, &n, &itr);
	if (is_negative)
		ptr[itr++] = '-';
	ptr[itr] = '\0';
	ft_reverse_str(ptr, itr);
	return (ptr);
}

// int	main(void)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = ft_itoa(-2147483648LL);
// 	while (ptr && ptr[i] != '\0')
// 	{
// 		printf("LOOPER: %c\n", ptr[i]);
// 		i++;
// 	}
// 	return (0);
// }
