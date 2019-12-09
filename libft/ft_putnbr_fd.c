/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:34:21 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/14 23:36:18 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int chfr;
	int one;

	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n == -2147483648)
	{
		ft_putchar_fd(50, fd);
		n = 147483648;
	}
	chfr = 1;
	one = n;
	while ((one /= 10) != 0)
		chfr *= 10;
	while (chfr != 0)
	{
		one = n / chfr;
		n %= chfr;
		chfr /= 10;
		ft_putchar_fd(one + '0', fd);
	}
}
