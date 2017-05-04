/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:12:18 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 17:59:50 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	v;

	v = -1;
	if (src == dst)
		return (0);
	while ((++v < n) && src[v])
		dst[v] = src[v];
	v--;
	while (++v < n)
		dst[v] = 0;
	return (dst);
}
