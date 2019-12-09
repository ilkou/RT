/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:09:52 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/15 22:15:48 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cas;

	cas = (char*)malloc(sizeof(char) * len);
	ft_memcpy(cas, src, len);
	ft_memcpy(dst, cas, len);
	return ((void*)dst);
}
