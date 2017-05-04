/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getargs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:39:31 by aduban            #+#    #+#             */
/*   Updated: 2015/01/08 13:52:16 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getargstwo(t_flags *options, va_list args, int i)
{
	if (options[i].conv == 'u')
		return (printu(va_arg(args, long long), options[i]));
	else if (options[i].conv == 'U')
		return (printbigu(va_arg(args, unsigned long), options[i]));
	else if (options[i].conv == 'x')
		return (printxx(va_arg(args, unsigned long), 1, options[i]));
	else if (options[i].conv == 'X')
		return (printxx(va_arg(args, unsigned long long), 0, options[i]));
	else if (options[i].conv == 'c')
		return (printc(va_arg(args, int), options[i]));
	else if (options[i].conv == 'C')
		return (printbigc(va_arg(args, int), options[i]));
	else
		return (0);
}

int		getargs(t_flags *options, va_list args, int i)
{
	if (options[i].conv == 's' && options[i].l == 0)
		return (prints(va_arg(args, char *), options[i]));
	else if ((options[i].conv == 's' && options[i].l == 1) ||
			options[i].conv == 'S')
		return (printls(va_arg(args, wchar_t *), options[i]));
	else if (options[i].conv == 'd' || options[i].conv == 'i')
		return (printid(va_arg(args, long long), options[i]));
	else if (options[i].conv == 'D')
		return (printbigd(va_arg(args, long long), options[i]));
	else if (options[i].conv == 'p')
		return (printp(va_arg(args, void *), options[i]));
	else if (options[i].conv == 'o')
		return (printo(va_arg(args, unsigned long long), options[i]));
	else if (options[i].conv == 'O')
		return (printbigo(va_arg(args, unsigned long), options[i]));
	else
		return (getargstwo(options, args, i));
}
