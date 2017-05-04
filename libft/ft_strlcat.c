/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:15:43 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 17:25:46 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l;
	size_t	t;
	int		u;

	u = 0;
	t = -1;
	l = ft_strlen(dest) + ft_strlen(src);
	while (dest[++t] && (t < size))
		;
	if (t == size)
		return (ft_strlen((char *)src) + t);
	while (*(src + u) && t < (size - 1))
	{
		*(dest + t) = *(src + u);
		t++;
		u++;
	}
	*(dest + t) = '\0';
	return (l);
}
