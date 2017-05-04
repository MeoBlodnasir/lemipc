/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:59:35 by aduban            #+#    #+#             */
/*   Updated: 2015/02/11 13:50:01 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		afficher_zero(t_flags options, int h)
{
	if (options.prec && !options.precis)
		return (0);
	if (h)
		ft_putchar('0');
	return (1);
}

int		displaynb2(t_flags options, int size)
{
	int x;

	x = 0;
	if (options.precis)
	{
		options.precis = options.precis - size;
		while (options.precis)
		{
			x++;
			options.precis--;
		}
	}
	return (x);
}

int		displaynb(t_flags options, char *tmp, char tampon[N_LG_MAX], int size)
{
	int x;

	x = 0;
	if (options.precis)
	{
		options.precis = options.precis - size;
		while (options.precis)
		{
			x++;
			ft_putchar('0');
			options.precis--;
		}
	}
	while (++tmp != &tampon[N_LG_MAX])
		ft_putchar(*tmp);
	return (x);
}

int		afficher_nombre(unsigned long long n, unsigned int base,
		t_flags options, int h)
{
	char	*c_base;
	char	tampon[N_LG_MAX];
	char	*tmp;
	int		size;

	c_base = options.conv == 'X' ? C_BASENUMMAX_MAJ : C_BASENUMMAX_MIN;
	tmp = &tampon[N_LG_MAX - 1];
	*tmp = 0;
	if (n == 0)
		return (afficher_zero(options, h));
	else
	{
		while (n > 0)
		{
			*tmp-- = c_base[n % base];
			n /= base;
		}
		size = &tampon[N_LG_MAX - 1] - tmp;
		if (h)
			size += displaynb(options, tmp, tampon, size);
		else
			size += displaynb2(options, size);
		return (size);
	}
}

int		calc(unsigned long long n, int k)
{
	static int i = 0;

	if (k == 1)
	{
		i = 0;
		return (0);
	}
	if (n > 9)
	{
		calc(n / 10, 0);
		calc(n % 10, 0);
	}
	else
		i++;
	return (i);
}
