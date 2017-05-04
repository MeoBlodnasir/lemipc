/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:32:46 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 18:15:36 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		finalprints(char *str, t_flags options)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (options.prec == 1)
	{
		if (options.precis)
			options.size = options.precis;
		while (str[i] && i < options.size)
		{
			ft_putchar(str[i]);
			x++;
			i++;
		}
	}
	else
	{
		x = ft_strlen(str);
		ft_putstr(str);
	}
	return (x);
}

int		printswidth(t_flags options, int *j)
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
	(*j)++;
	return (x);
}

int		prints(char *str, t_flags options)
{
	int	j;
	int	x;

	x = 0;
	if (!str)
		str = ft_strdup("(null)");
	if (options.moins)
		x += finalprints(str, options);
	if (options.size)
	{
		j = ft_strlen(str);
		while (j < options.size)
			x += printswidth(options, &j);
	}
	if (!options.moins)
		x += finalprints(str, options);
	return (x);
}
