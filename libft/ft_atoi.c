/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:25:39 by aduban            #+#    #+#             */
/*   Updated: 2015/02/26 13:58:07 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

void	error(long int value, int sign)
{
	if ((value > 2147483647 && sign != -1) || (value > 2147483648
				&& sign == -1))
	{
		ft_putendl("Error");
		exit(0);
	}
}

int		ft_atoi(const char *str)
{
	long int		value;
	int				sign;
	char			nb;

	value = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (sign == -1 || *str == '+')
		str++;
	if (!(ft_isdigit(*str)))
		return (0);
	while ((nb = *str++) >= '0' && nb <= '9')
	{
		value = value * 10;
		value = value + (int)(nb - '0');
		error(value, sign);
	}
	return ((int)(value * sign));
}
