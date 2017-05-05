/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:26:40 by aduban            #+#    #+#             */
/*   Updated: 2014/11/09 13:34:23 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
		n--;
	}
	return (dst);
}
