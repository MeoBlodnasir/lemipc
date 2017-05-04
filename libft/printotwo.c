/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printotwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:18:05 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:21:19 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		finalprinto(unsigned long i, t_flags options)
{
	int x;

	x = 0;
	if (options.diese == 1 && (i != 0 || options.prec))
	{
		ft_putchar('0');
		x++;
	}
	if (options.hh)
		afficher_nombre((unsigned char)i, 8, options, 1);
	else if (options.h)
		afficher_nombre((unsigned short)i, 8, options, 1);
	else if (options.ll)
		afficher_nombre((unsigned long long)i, 8, options, 1);
	else if (options.l)
		afficher_nombre((unsigned long)i, 8, options, 1);
	else if (options.j)
		afficher_nombre((uintmax_t)i, 8, options, 1);
	else if (options.z)
		afficher_nombre((size_t)i, 8, options, 1);
	else
		afficher_nombre(i, 8, options, 1);
	return (x);
}
