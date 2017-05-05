/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:47:07 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 18:20:10 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;
	int		i;

	i = -1;
	ch = 0;
	while (s[++i])
		if (s[i] == (char)c)
			ch = (char*)(s + i);
	if ((char)c == 0)
		return ((char*)(s + i));
	return (ch);
}
