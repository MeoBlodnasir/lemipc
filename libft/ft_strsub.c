/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:32:13 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 19:18:18 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*n;
	unsigned int	i;

	i = -1;
	n = (char*)malloc(sizeof(char) * (len + 1));
	if (n == NULL)
		return (0);
	while (++i < len)
		n[i] = s[start + i];
	n[len] = 0;
	return (n);
}
