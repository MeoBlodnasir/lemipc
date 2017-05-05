/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:23:22 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 16:39:57 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	int			i;

	dst2 = dst;
	src2 = src;
	i = 0;
	if (src2 <= dst2)
	{
		dst2 = dst2 + (len - 1);
		src2 = src2 + (len - 1);
		while (len)
		{
			dst2[i] = src2[i];
			i--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
