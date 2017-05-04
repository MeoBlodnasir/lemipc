/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:31:13 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 16:06:27 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	int				i;

	str = s;
	i = 0;
	while (n)
	{
		if (str[i] == (char)c)
			return ((char*)str + i);
		i++;
		n--;
	}
	return (NULL);
}
