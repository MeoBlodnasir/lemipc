/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:44:41 by aduban            #+#    #+#             */
/*   Updated: 2014/11/10 16:55:21 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	int				v;

	v = -1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	while (++v < (int)size)
		str[v] = 0;
	return (str);
}
