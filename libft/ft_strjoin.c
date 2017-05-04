/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:04:09 by aduban            #+#    #+#             */
/*   Updated: 2014/11/08 17:20:36 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t;
	char	*tra;

	t = ft_strlen(s1) + ft_strlen(s2);
	tra = ft_strnew(t);
	ft_strcpy(tra, s1);
	ft_strcpy((tra + ft_strlen(s1)), s2);
	return (tra);
}
