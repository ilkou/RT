/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:38:30 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/19 19:01:55 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dest;
	int		i;

	dest = (char*)b;
	i = 0;
	while (i < (int)len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	b = (void*)dest;
	return (b);
}
