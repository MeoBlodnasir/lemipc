/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:04:33 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:23:51 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getsizeu(long long i, t_flags options)
{
	if (options.hh)
		return (afficher_nombre((unsigned char)i, 10, options, 0));
	else if (options.h)
		return (afficher_nombre((unsigned short)i, 10, options, 0));
	else if (options.ll)
		return (afficher_nombre((unsigned long long)i, 10, options, 0));
	else if (options.l)
		return (afficher_nombre(i, 10, options, 0));
	else if (options.j)
		return (afficher_nombre((uintmax_t)i, 10, options, 0));
	else if (options.z)
		return (afficher_nombre((size_t)i, 10, options, 0));
	else
		return (afficher_nombre(i, 10, options, 0));
	if (i == 0 && options.prec && !options.precis)
		return (0);
}

int		printuplus(t_flags options, long long i)
{
	int x;

	x = 0;
	finalprintu(i, options);
	if (options.precis)
		x += options.precis - getsizeu(i, options);
	return (x);
}

int		printuwidth(t_flags options)
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
	return (x);
}

int		printu(long long i, t_flags options)
{
	int x;
	int k;

	x = 0;
	if (options.moins)
		x += printuplus(options, i);
	if (options.size)
	{
		k = getsizeu(i, options);
		if (options.precis)
			options.size -= options.precis - getsizeu(i, options);
		while (k < options.size)
		{
			x += printuwidth(options);
			k++;
		}
	}
	if (!options.moins)
		x += printuplus(options, i);
	x += getsizeu(i, options);
	return (x);
}

int		printbigu(long long i, t_flags options)
{
	options.l = 1;
	options.hh = 0;
	options.h = 0;
	options.j = 0;
	options.z = 0;
	options.ll = 0;
	return (printu(i, options));
}
