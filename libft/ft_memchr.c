/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:30:47 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/06 16:31:12 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
