/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:08:50 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/19 21:53:42 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (*(char*)s == '\0' && size == 1)
		return ((char*)s);
	while (size)
	{
		if (*((char*)s + size) == (char)c)
			return ((char*)s + size);
		size--;
	}
	if (*((char*)s + size) == (char)c)
		return ((char*)s + size);
	return (NULL);
}
