/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:24:21 by aduban            #+#    #+#             */
/*   Updated: 2015/02/11 13:49:13 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printpplus(t_flags options, void *thing)
{
	int x;

	x = 0;
	if (!options.size || !options.zero || options.moins)
		ft_putstr("0x");
	afficher_nombre((long long)thing, 16, options, 1);
	x += (options.zero) ? afficher_nombre((long long)thing, 16, options, 0) + 2
		: afficher_nombre((long long)thing, 16, options, 0) + 2;
	return (x);
}

int		printpwidth(t_flags options, int *j)
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
		x++;
		ft_putchar(' ');
	}
	(*j)++;
	return (x);
}

int		printp(void *thing, t_flags options)
{
	int	j;
	int x;

	x = 0;
	if (options.moins)
		x += printpplus(options, thing);
	if (options.size)
	{
		if (options.zero && !options.moins)
			ft_putstr("0x");
		j = afficher_nombre((long long)thing, 16, options, 0) + 2;
		while (j < options.size)
		{
			x += printpwidth(options, &j);
		}
	}
	if (!options.moins)
		x += printpplus(options, thing);
	return (x);
}
