/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:10:52 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:18:39 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printoplus(t_flags options, unsigned long i)
{
	int x;

	x = 0;
	x += finalprinto(i, options);
	if (options.precis)
		x += options.precis - afficher_nombre(i, 8, options, 0);
	return (x);
}

int		printowidth(t_flags options, int *j)
{
	int x;

	x = 0;
	if (options.zero && !options.moins)
	{
		ft_putchar('0');
		x++;
	}
	else
	{
		ft_putchar(' ');
		x++;
	}
	(*j)++;
	return (x);
}

int		printospec(t_flags options, unsigned long i)
{
	int x;

	x = 0;
	if (!options.moins)
		x += printoplus(options, i);
	if (options.hh)
		x += afficher_nombre((unsigned char)i, 8, options, 0);
	else if (options.h)
		x += afficher_nombre((unsigned short)i, 8, options, 0);
	else
		x += afficher_nombre(i, 8, options, 0);
	return (x);
}

int		printo(unsigned long i, t_flags options)
{
	int x;
	int	j;

	x = 0;
	if (options.moins)
		x += printoplus(options, i);
	if (options.size)
	{
		j = afficher_nombre(i, 8, options, 0);
		if ((int)i < 0 && options.prec && !options.hh && !options.h &&
				!options.ll && !options.l && !options.j && !options.z)
			j--;
		if (options.diese)
		{
			x++;
			j++;
		}
		if (options.precis)
			options.size -= options.precis - afficher_nombre(i, 8, options, 0);
		while (j < options.size)
			x += printowidth(options, &j);
	}
	x += printospec(options, i);
	return (x);
}

int		printbigo(unsigned long i, t_flags options)
{
	options.l = 1;
	options.hh = 0;
	options.h = 0;
	options.j = 0;
	options.z = 0;
	options.ll = 0;
	return (printo(i, options));
}
