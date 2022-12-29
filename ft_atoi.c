/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:22:23 by doduwole          #+#    #+#             */
/*   Updated: 2022/12/23 08:48:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_validate(const char *str, int *is_neg, int *is_pos, long *i)
{
	while (str[*i] != '\0' && (!(str[*i] >= '0' && str[*i] <= '9')))
	{
		if ((*is_pos > 0 || *is_neg > 0)
			&& !(str[*i] >= '0' && str[*i] <= '9'))
			return (0);
		if (str[*i] == 45)
			*is_neg += 1;
		else if (str[*i] == 43)
			*is_pos += 1;
		else if (str[*i] == 32)
		{
		}
		else
			return (0);
		if (*is_pos > 0 && *is_neg > 0)
			return (0);
		*i += 1;
	}
	return (*i);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		is_neg;
	int		is_pos;

	i = 0;
	nbr = 0;
	is_neg = 0;
	is_pos = 0;
	if (ft_validate(&str[0], &is_neg, &is_pos, &i) == 0)
		return (0);
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && is_neg == 0)
			return (2147483647);
		if (nbr > 2147483648 && is_neg > 0)
			return (-2147483648);
		i++;
	}
	if (is_neg > 0)
		return (-nbr);
	return (nbr);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 		printf("%i", ft_atoi(argv[1]));
// 	return (0);
// }
