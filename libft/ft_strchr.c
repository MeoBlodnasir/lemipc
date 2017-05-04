/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:24:59 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 16:51:40 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int t;

	t = 0;
	if ((char)c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (s[t] != (char)c && s[t])
	{
		t++;
	}
	if (s[t] == (char)c)
		return ((char*)(s + t));
	return (0);
}
