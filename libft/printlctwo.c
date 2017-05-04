/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlctwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:09:56 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:12:29 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dectobin(unsigned long long n, unsigned int base)
{
	char	*c_base;
	char	tampon[N_LG_MAX];
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	c_base = C_BASENUMMAX_MIN;
	tmp = &tampon[N_LG_MAX - 1];
	*tmp = 0;
	while (n > 0)
	{
		*tmp-- = c_base[n % base];
		n /= base;
	}
	str = (char*)malloc(sizeof(char) * ((&tampon[N_LG_MAX - 1] - tmp) + 1));
	while (++tmp != &tampon[N_LG_MAX])
	{
		str[i] = *tmp;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		power(int i, int j)
{
	int k;

	if (j == 0)
		return (1);
	k = i;
	j--;
	while (j > 0)
	{
		i *= k;
		j--;
	}
	return (i);
}

int		getnboct(char *str)
{
	int k;
	int j;

	k = ft_strlen(str);
	if (k <= 7)
		j = 1;
	else if (k > 7 && k <= 11)
		j = 2;
	else if (k > 11 && k <= 16)
		j = 3;
	else
		j = 4;
	return (j);
}
