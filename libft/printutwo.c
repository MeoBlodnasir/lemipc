/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printutwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:22:15 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:23:49 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	finalprintu(long long i, t_flags options)
{
	if (options.hh)
		afficher_nombre((unsigned char)i, 10, options, 1);
	else if (options.h)
		afficher_nombre((unsigned short)i, 10, options, 1);
	else if (options.ll)
		afficher_nombre((unsigned long long)i, 10, options, 1);
	else if (options.l)
		afficher_nombre((unsigned long)i, 10, options, 1);
	else if (options.j)
		afficher_nombre((uintmax_t)i, 10, options, 1);
	else if (options.z)
		afficher_nombre((size_t)i, 10, options, 1);
	else
		afficher_nombre(i, 10, options, 1);
}
