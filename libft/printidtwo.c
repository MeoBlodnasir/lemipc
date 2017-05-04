/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printidtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:05:08 by aduban            #+#    #+#             */
/*   Updated: 2015/03/21 16:06:09 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getidsizetwo(unsigned long a, t_flags options, int j)
{
	if (options.l)
	{
		j = (options.negative) ? afficher_nombre((long)a, 10, options, 0) + 1 :
			afficher_nombre((long)a, 10, options, 0);
	}
	else if (options.j)
	{
		j = (options.negative) ? afficher_nombre((intmax_t)a, 10, options, 0) +
			1 : afficher_nombre((intmax_t)a, 10, options, 0);
	}
	else if (options.z)
		j = (options.negative) ? afficher_nombre((size_t)a, 10, options, 0) + 1
			: afficher_nombre((size_t)a, 10, options, 0);
	else if (!options.hh && !options.h && !options.ll)
	{
		j = (options.negative) ? calc((int)a, 0) + 1 : calc((int)a, 0);
		calc(0, 1);
	}
	return (j);
}

int		getidsize(unsigned long long a, t_flags options)
{
	int j;

	j = 0;
	if (options.hh)
		j = (options.negative) ? afficher_nombre((unsigned char)a, 10, options,
				0) + 1 : afficher_nombre((unsigned char)a, 10, options, 0);
	else if (options.h)
		j = ft_strlen(ft_itoa((short)a));
	else if (options.ll)
		j = (options.negative) ? afficher_nombre((long)a, 10, options, 0) + 1 :
			afficher_nombre((long)a, 10, options, 0);
	j = getidsizetwo(a, options, j);
	if (options.plus && !options.negative)
		j++;
	if (a == 0 && options.prec && !options.precis)
		return (0);
	return (j);
}

void	finalprintid(unsigned long long a, t_flags options)
{
	if (!(options.prec && (options.size == 0) && a == 0))
	{
		if (options.hh)
			ft_putnbr((unsigned char)a);
		else if (options.h)
			ft_putlnbr((unsigned short)a);
		else if (options.ll)
			afficher_nombre((long long)a, 10, options, 1);
		else if (options.l)
			afficher_nombre((long)a, 10, options, 1);
		else if (options.j)
			afficher_nombre((intmax_t)a, 10, options, 1);
		else if (options.z)
			afficher_nombre((size_t)a, 10, options, 1);
		else
			afficher_nombre(a, 10, options, 1);
	}
}

int		printidplus(unsigned long long a, t_flags options)
{
	int x;

	x = 0;
	if ((options.plus || options.space) && !options.negative)
	{
		if (options.size && !options.prec)
			options.size--;
		if ((options.size && options.moins) || (options.plus || (options.plus
						&& options.space)))
		{
			ft_putchar('+');
		}
		else if (options.space)
		{
			x++;
			ft_putchar(' ');
		}
	}
	finalprintid(a, options);
	return (x);
}
