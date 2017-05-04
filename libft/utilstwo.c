/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:24:17 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:25:10 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printprc(void)
{
	ft_putchar('%');
	return (1);
}

int		isthere(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		getsize(const char *str, int i)
{
	int		k;
	int		j;
	char	*tt;

	k = 0;
	j = i;
	while (ft_isdigit(str[i]))
	{
		i++;
		k++;
	}
	tt = ft_strsub(str, j, k);
	return (ft_atoi(tt));
}

void	ft_putlnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putlnbr(n / 10);
		ft_putlnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
