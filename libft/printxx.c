/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printxx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 18:11:34 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 18:39:45 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	finalprintxx(unsigned long long i, int a, t_flags options)
{
	if (options.diese && a && i)
		ft_putstr("0x");
	else if (options.diese && !a && i)
		ft_putstr("0X");
	if (options.hh)
		afficher_nombre((unsigned char)i, 16, options, 1);
	else if (options.h)
		afficher_nombre((unsigned short)i, 16, options, 1);
	else if (options.ll)
		afficher_nombre((unsigned long long)i, 16, options, 1);
	else if (options.l)
		afficher_nombre((unsigned long)i, 16, options, 1);
	else if (options.j)
		afficher_nombre((uintmax_t)i, 16, options, 1);
	else if (options.z)
		afficher_nombre((size_t)i, 16, options, 1);
	else
		afficher_nombre(i, 16, options, 1);
}

int		getsizexx(unsigned long long i, t_flags options)
{
	int j;

	if (options.hh)
		j = afficher_nombre((unsigned char)i, 16, options, 0);
	else if (options.h)
		j = afficher_nombre((unsigned short)i, 16, options, 0);
	else if (options.ll)
		j = afficher_nombre((unsigned long long)i, 16, options, 0);
	else if (options.l)
		j = afficher_nombre((unsigned long)i, 16, options, 0);
	else if (options.j)
		j = afficher_nombre((uintmax_t)i, 16, options, 0);
	else if (options.z)
		j = afficher_nombre((size_t)i, 16, options, 0);
	else
		j = afficher_nombre(i, 16, options, 0);
	if (options.diese && i)
		j += 2;
	if (i == 0 && options.prec && !options.precis)
		return (0);
	return (j);
}

int		printxxplus(t_flags options, unsigned long long i, int a)
{
	int x;

	x = 0;
	finalprintxx(i, a, options);
	if (options.precis)
		x += options.precis - getsizexx(i, options);
	return (x);
}

int		printxxwidth(t_flags options)
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

int		printxx(unsigned long long i, int a, t_flags options)
{
	int x;
	int	j;

	x = 0;
	if (options.moins)
		x += printxxplus(options, i, a);
	if (options.size)
	{
		j = getsizexx(i, options);
		if (options.precis)
			options.size -= options.precis - getsizexx(i, options);
		while (j < options.size)
		{
			x += printxxwidth(options);
			j++;
		}
	}
	if (!options.moins)
		x += printxxplus(options, i, a);
	x += getsizexx(i, options);
	return (x);
}
