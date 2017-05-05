/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:21:12 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 15:52:10 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			size;
	long int		i;
	char			*str;

	i = (long int)n;
	if (n < 0)
		size = 2;
	else
		size = 1;
	while ((i = i / 10))
		size++;
	if (!(str = ft_strnew(sizeof(char) * size + 1)))
		return (NULL);
	i = (long int)n;
	i = n < 0 ? -i : i;
	while (i > 9)
	{
		str[size - 1] = i % 10 + '0';
		i = i / 10;
		size--;
	}
	str[size - 1] = i + '0';
	if (size == 2)
		str[0] = '-';
	return (str);
}
