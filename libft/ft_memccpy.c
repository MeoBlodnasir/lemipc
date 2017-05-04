/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:12:18 by aduban            #+#    #+#             */
/*   Updated: 2014/11/09 13:32:32 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dst2;
	const char	*src2;
	int			i;

	dst2 = dst;
	src2 = src;
	i = 0;
	while (n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == c)
			return ((unsigned char *)dst2 + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
