/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:37:52 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:16:59 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*minifillnb(int *nb, char **tab, int g, int v)
{
	int i;
	int n;

	n = 0;
	i = 7;
	while (i >= 0)
	{
		if (tab[g][i] == '1')
			nb[v] = nb[v] + (power(2, n));
		n++;
		i--;
	}
	return (nb);
}

int		*fillnb(char **tab, int j)
{
	int v;
	int g;
	int *nb;

	v = 0;
	g = j;
	g--;
	nb = (int*)malloc(sizeof(int) * j);
	while (v < j)
	{
		nb[v] = 0;
		nb = minifillnb(nb, tab, g, v);
		v++;
		g--;
	}
	return (nb);
}

int		finalprintlc(int j, int *nb, int i)
{
	int v;
	int x;

	x = 0;
	v = j;
	v--;
	while (v >= 0)
	{
		x++;
		if (i)
			write(1, &(nb[v]), 1);
		v--;
	}
	return (x);
}

int		printlc(int i, int l)
{
	char	*str;
	char	*hip;
	int		*nb;
	int		j;
	char	**tab;

	str = dectobin(i, 2);
	j = getnboct(str);
	tab = filltab(j);
	hip = fillhip(tab, j);
	hip = rectifhip(hip, str);
	tab = subtab(tab, hip);
	nb = fillnb(tab, j);
	return (finalprintlc(j, nb, l));
}
