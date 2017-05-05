/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:47:34 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 19:12:40 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int t;
	int i;

	i = 0;
	if (s2 == NULL || s2[i] == 0)
		return ((char*)s1);
	while (s1[i])
	{
		t = 0;
		while (s1[t + i] == s2[t])
			if (s2[++t] == '\0')
				return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
