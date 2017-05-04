/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:56:33 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 17:59:14 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printbigc(int i, t_flags options)
{
	options.l = 1;
	options.hh = 0;
	options.h = 0;
	options.j = 0;
	options.z = 0;
	options.ll = 0;
	return (printc(i, options));
}

int		finalprintc(t_flags options, int i)
{
	int x;

	x = 0;
	if (options.l)
	{
		return (printlc(i, 1));
	}
	else
	{
		ft_putchar(i);
		x++;
	}
	return (x);
}

int		putzz(t_flags options)
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
		ft_putchar(' ');
		x++;
	}
	return (x);
}

int		printc(int i, t_flags options)
{
	int j;
	int x;

	x = 0;
	j = 1;
	if (options.moins)
		x += finalprintc(options, i);
	if (options.size)
	{
		while (j < options.size)
		{
			x += putzz(options);
			j++;
		}
	}
	if (!options.moins)
		x += finalprintc(options, i);
	return (x);
}
