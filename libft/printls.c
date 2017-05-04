/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:50:13 by aduban            #+#    #+#             */
/*   Updated: 2015/02/11 13:48:37 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		finalprintls(t_flags options, wchar_t *str, int l)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (options.precis && options.prec)
	{
		while (str[i] && i < (options.precis / 4))
		{
			x += printlc(str[i], l);
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[i])
		{
			x += printlc(str[i], l);
			i++;
		}
	}
	return (x);
}

int		putz(t_flags options)
{
	int x;

	x = 0;
	if (options.zero && !options.moins && !options.prec)
	{
		x++;
		ft_putchar('0');
	}
	else if (!options.prec)
	{
		x++;
		ft_putchar(' ');
	}
	return (x);
}

int		printls(wchar_t *str, t_flags options)
{
	int	j;
	int x;

	x = 0;
	if (!str)
		str = L"(null)";
	if (options.moins)
		x += finalprintls(options, str, 1);
	if (options.size)
	{
		j = finalprintls(options, str, 0);
		while (j < options.size)
		{
			x += putz(options);
			j++;
		}
	}
	if (!options.moins)
		x += finalprintls(options, str, 1);
	return (x);
}
