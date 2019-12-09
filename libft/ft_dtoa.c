/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:30:11 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/16 16:36:21 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double n)
{
	char	*nbr;
	char	*tmp;
	char	*tmp2;
	int		decimal;

	tmp2 = n < 0.0 && n > -1.0 ? ft_mystrjoin("-", ft_itoa((int)n), 1)
		: ft_itoa((int)n);
	n = n < 0.0 ? -n : n;
	n = n - floor(n);
	tmp = ft_mystrjoin(tmp2, ".", 0);
	n *= 10;
	decimal = (int)(n * 10) % 10;
	n = ((int)n < 9 && decimal >= 5.0) ? n + 1 : n;
	tmp2 = ft_itoa(n);
	nbr = ft_mystrjoin(tmp, tmp2, 2);
	return (nbr);
}
