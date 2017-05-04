/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:33:14 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 17:07:12 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	int		l;
	char	*ttr;
	int		t;

	t = 0;
	l = ft_strlen(s);
	ttr = (char *)malloc(sizeof(*ttr) * (l + 1));
	while (s[t])
	{
		ttr[t] = s[t];
		t++;
	}
	ttr[t] = s[t];
	return (ttr);
}
