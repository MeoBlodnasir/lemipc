/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlcthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:13:43 by aduban            #+#    #+#             */
/*   Updated: 2015/01/06 19:14:42 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**filltab(int j)
{
	char	**tab;
	int		h;

	h = 0;
	tab = (char**)malloc(sizeof(char*) * j);
	while (h < j)
	{
		if (h == 0 && j == 1)
			tab[h] = ft_strdup("03333333");
		else if (h == 0 && j == 2)
			tab[h] = ft_strdup("11033333");
		else if (h == 0 && j == 3)
			tab[h] = ft_strdup("11103333");
		else if (h == 0 && j == 4)
			tab[h] = ft_strdup("11110333");
		if (h != 0)
			tab[h] = ft_strdup("10333333");
		h++;
	}
	return (tab);
}

char	*fillhip(char **tab, int j)
{
	char	*hip;
	int		h;

	h = 0;
	hip = ft_strdup("");
	while (j >= 1)
	{
		hip = ft_strjoin(hip, tab[h]);
		h++;
		j--;
	}
	return (hip);
}

char	*rectifhip(char *hip, char *str)
{
	int h;
	int j;

	h = ft_strlen(str);
	j = ft_strlen(hip);
	j--;
	h--;
	while (h >= 0)
	{
		if (hip[j] == '3')
		{
			hip[j] = str[h];
			h--;
		}
		j--;
	}
	j = 0;
	while (hip[j])
	{
		if (hip[j] == '3')
			hip[j] = '0';
		j++;
	}
	return (hip);
}

char	**subtab(char **tab, char *hip)
{
	int	j;
	int	h;
	int	i;

	j = ft_strlen(hip) / 8;
	h = 0;
	i = 0;
	while (h < j)
	{
		tab[h] = ft_strsub(hip, i, 8);
		i += 8;
		h++;
	}
	return (tab);
}
