/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 08:35:06 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/13 16:19:08 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;
	size_t	j;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size >= size_dst)
	{
		i = ft_strlen((const char*)dst);
		j = 0;
		while (i < size - 1 && src[j] != '\0')
		{
			dst[i] = *((char*)src + j);
			i++;
			j++;
		}
		dst[i] = '\0';
		return (size_dst + size_src);
	}
	else
		return (size_src + size);
	return (0);
}
