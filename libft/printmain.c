/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:20:42 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:17:39 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	browseflags(const char *format, int *i, char *str)
{
	(*i)++;
	while (isthere(format[*i], str) || ft_isdigit(format[*i]))
		(*i)++;
	(*i)++;
}

int		gettheg(int i, const char *format)
{
	int g;

	g = i;
	g++;
	while (format[g] && isthere(format[g], "sSpdDioOuUxXc%C"))
		g++;
	return (g);
}

int		writestuff(const char *format, int i)
{
	int x;

	x = 0;
	ft_putchar(format[i]);
	x++;
	return (x);
}

int		browse(const char *format, int *i, t_flags *options, va_list args)
{
	int			x;
	static int	k = 0;
	static int	n = 0;

	x = 0;
	if (format[gettheg(*i, format)] != '\0')
	{
		if (options[k].conv != '%')
			x += getargs(options, args, k);
		else
		{
			x += printprc();
			n++;
		}
		k++;
		browseflags(format, i, "sSpdDioOuUxXc%C");
	}
	else
		browseflags(format, i, "#0-+hljz .");
	if (options[k + n].diese == 3 || (k == 1 && n > 0))
	{
		k = 0;
		n = 0;
	}
	return (x);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	*options;
	int		i;
	int		x;

	x = 0;
	i = 0;
	va_start(args, format);
	options = getinc(format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			x += writestuff(format, i);
			i++;
		}
		else if (format[i] == '%')
		{
			x += browse(format, &i, options, args);
		}
	}
	va_end(args);
	return (x);
}
