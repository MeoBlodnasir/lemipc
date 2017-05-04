/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:18:09 by aduban            #+#    #+#             */
/*   Updated: 2015/03/04 17:27:15 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**bigger(char **array, int len)
{
	char	**next;

	if (!(next = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	if (array != NULL)
	{
		while (len > 0)
		{
			next[len - 1] = array[len - 1];
			len--;
		}
		free(array);
	}
	return (next);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	size;
	int		start;
	int		i;
	char	**tab;

	i = 0;
	size = 1;
	tab = (char **)malloc(1);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (s[i] == 0)
			break ;
		while (s[i] != c && s[i])
			i++;
		size++;
		if (!(tab = bigger(tab, size)))
			return (0);
		if (!(tab[size - 2] = ft_strsub(s, start, i - start)))
			return (0);
	}
	tab[size - 1] = NULL;
	return (tab);
}
