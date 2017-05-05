/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:53:50 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 19:24:14 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	l;
	char			*n;

	i = 0;
	l = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[l + i])
		l++;
	while ((s[l + i] == ' ' || s[l + i] == '\n' || s[l + i] == '\t' ||
		s[l + i] == 0) && l)
		l--;
	l++;
	n = (char*)malloc(sizeof(char) * (l + 1));
	if (n == NULL)
		return (0);
	n[l] = 0;
	while (l-- > 0)
		n[l] = s[l + i];
	return (n);
}
