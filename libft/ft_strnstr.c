/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:25:39 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 18:16:56 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			t;
	unsigned int	j;

	if (s2 == NULL || *s2 == 0)
		return ((char*)s1);
	while (*s1 != 0 && n)
	{
		j = 0;
		t = n;
		while (s1[j] == s2[j] && t)
		{
			if (s2[++j] == '\0')
				return ((char*)s1);
			t--;
		}
		s1++;
		n--;
	}
	return (0);
}
