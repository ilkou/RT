/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:18:47 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/06 20:19:45 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen((const char*)s1);
	j = 0;
	while (*((char*)s2 + j) != '\0')
	{
		s1[i] = *((char*)s2 + j);
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
