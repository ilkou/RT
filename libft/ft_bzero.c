/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:56:44 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/05 22:03:31 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	if (n)
	{
		dest = (char*)s;
		while (i < (int)n)
		{
			dest[i] = 0;
			i++;
		}
		s = (void*)dest;
	}
}
