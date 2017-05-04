/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:47:46 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 17:42:58 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	v;
	unsigned int	k;
	char			*str;

	v = ft_strlen(s);
	k = 0;
	str = (char*)malloc(sizeof(char) * (v + 1));
	if (str == NULL)
		return (0);
	while (*(s + k) != '\0')
	{
		*(str + k) = f(k, *(s + k));
		k++;
	}
	str[v] = '\0';
	return (str);
}
