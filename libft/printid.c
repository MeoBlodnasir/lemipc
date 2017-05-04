/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:39:07 by aduban            #+#    #+#             */
/*   Updated: 2015/02/11 13:47:30 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printtheid(t_flags options, unsigned long long a)
{
	int x;

	x = 0;
	if (options.negative && !options.zero)
	{
		ft_putchar('-');
	}
	x += printidplus(a, options);
	if (options.precis)
		x += options.precis - getidsize(a, options);
	return (x);
}

int		printidwidth(t_flags options, int *j)
{
	int x;

	x = 0;
	if (options.zero && !options.moins)
	{
		x++;
		ft_putchar('0');
	}
	else
	{
		x++;
		ft_putchar(' ');
	}
	(*j)++;
	return (x);
}

int		printidd(unsigned long long a, t_flags options)
{
	int	j;
	int x;

	x = 0;
	{
		if (options.moins)
			x += printtheid(options, a);
		if (options.size)
		{
			j = getidsize(a, options);
			x += j;
			if ((options.negative && options.prec))
				j--;
			if (options.precis)
				options.size -= options.precis - getidsize(a, options);
			while (j < options.size)
				x += printidwidth(options, &j);
		}
		else
			x += getidsize(a, options);
		if (!options.moins)
			x += printtheid(options, a);
	}
	return (x);
}

int		printid(long long a, t_flags options)
{
	if (((int)a >= 0 && !options.l && !options.ll && !options.hh && !options.h
				&& !options.z && !options.j) || (options.h && (short)a >= 0) ||
			(options.hh && (signed char)a >= 0) || (options.ll && (long long)a
				>= 0) || (options.l && (long)a >= 0) || (options.z && a >= 0)
			|| (options.j && (intmax_t)a >= 0))
		return (printidd(a, options));
	else
	{
		if (options.zero)
			ft_putchar('-');
		options.negative = 1;
		return (printidd((int)-a, options));
	}
}

int		printbigd(long long a, t_flags options)
{
	options.l = 1;
	options.hh = 0;
	options.h = 0;
	options.j = 0;
	options.z = 0;
	options.ll = 0;
	return (printid(a, options));
}
