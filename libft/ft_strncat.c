/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:55:28 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/06 22:06:57 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen((const char*)s1);
	j = 0;
	while (*((const char*)s2 + j) != '\0' && j < n)
	{
		s1[i] = *((const char*)s2 + j);
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
