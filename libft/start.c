/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:46:27 by aduban            #+#    #+#             */
/*   Updated: 2015/03/23 16:18:46 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		fillflagstwo(t_flags options, const char *str, int i)
{
	options.diese = (str[i] == '#' || options.diese) ? 1 : 0;
	options.zero = (((str[i] == '0' || str[i] == '.') && !ft_isdigit(str[i -
					1])) || options.zero) ? 1 : 0;
	options.prec = (str[i] == '.' || options.prec) ? 1 : 0;
	options.moins = (str[i] == '-' || options.moins) ? 1 : 0;
	options.plus = (str[i] == '+' || options.plus) ? 1 : 0;
	options.hh = ((str[i] == 'h' && str[i + 1] == 'h') || options.hh) ? 1 : 0;
	options.h = ((str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h') ||
			options.h) ? 1 : 0;
	options.ll = ((str[i] == 'l' && str[i + 1] == 'l') || options.ll) ? 1 : 0;
	options.l = ((str[i] == 'l' && str[i + 1] != 'l') || options.l) ? 1 : 0;
	options.j = (str[i] == 'j' || options.j) ? 1 : 0;
	options.z = (str[i] == 'z' || options.z) ? 1 : 0;
	options.space = (str[i] == ' ' || options.space) ? 1 : 0;
	return (options);
}

t_flags		fillflags(t_flags options, const char *str, int i)
{
	options = fillflagstwo(options, str, i);
	if ((!ft_isdigit(str[i - 1]) || str[i - 1] == '0') && str[i - 1] != '.')
	{
		if (str[i] >= '1' && str[i] <= '9')
			options.size = getsize(str, i);
	}
	if (ft_isdigit(str[i]) && str[i - 1] == '.')
	{
		if (str[i] >= '1' && str[i] <= '9')
			options.precis = getsize(str, i);
	}
	if (options.prec)
		options.moins = 0;
	return (options);
}

t_flags		*initflags(t_flags *options, int i)
{
	int k;

	k = 0;
	while (k <= i)
	{
		options[k].precis = 0;
		options[k].diese = 0;
		options[k].zero = 0;
		options[k].moins = 0;
		options[k].plus = 0;
		options[k].hh = 0;
		options[k].h = 0;
		options[k].ll = 0;
		options[k].l = 0;
		options[k].j = 0;
		options[k].z = 0;
		options[k].size = 0;
		options[k].negative = 0;
		options[k].space = 0;
		k++;
	}
	options[k - 1].diese = 3;
	return (options);
}

int			nboptions(const char *format)
{
	int j;
	int g;
	int i;

	j = 0;
	i = 0;
	while (format[j])
	{
		if (format[j] == '%')
		{
			g = j;
			g++;
			while (format[g] && isthere(format[g], "sSpdDioOuUxXcC%"))
				g++;
			if (format[g] != '\0')
				i++;
		}
		j++;
	}
	return (i);
}

t_flags		*getinc(const char *format)
{
	t_flags	*options;
	int		i;
	int		j;

	i = nboptions(format);
	options = (t_flags *)malloc(sizeof(t_flags) * (i + 1));
	options = initflags(options, i);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (isthere(format[i], "sSpdDioOuUxXcC%"))
			{
				options[j] = fillflags(options[j], format, i);
				i++;
			}
			options[j++].conv = format[i];
		}
		i++;
	}
	return (options);
}
