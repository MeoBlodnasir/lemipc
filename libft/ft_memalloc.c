/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:55:50 by aduban            #+#    #+#             */
/*   Updated: 2014/11/18 18:30:29 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if (size)
	{
		str = (char *)malloc(sizeof(char) * size);
		if (str != 0)
		{
			while (size)
				str[size-- - 1] = '\0';
			return ((void *)str);
		}
	}
	return (0);
}
