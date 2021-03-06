/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:32:21 by aduban            #+#    #+#             */
/*   Updated: 2014/11/10 11:52:13 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tr;
	int				i;

	i = 0;
	tr = s;
	while (n)
	{
		tr[i] = '\0';
		i++;
		n--;
	}
}
