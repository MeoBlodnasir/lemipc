/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:54:03 by aduban            #+#    #+#             */
/*   Updated: 2014/11/10 11:56:40 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	v;
	char			*ttr;
	unsigned int	i;
	int				t;

	i = 0;
	t = 0;
	v = ft_strlen(s) + 1;
	ttr = (char*)malloc(sizeof(char) * v);
	if (ttr == NULL)
		return (0);
	while (s[t] != '\0')
	{
		ttr[i++] = f(s[t]);
		t++;
	}
	*(ttr + (v - 1)) = '\0';
	return (ttr);
}
