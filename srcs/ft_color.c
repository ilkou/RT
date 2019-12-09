/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:03:13 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/15 18:06:05 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_color		ft_add_c(t_color a, t_color b)
{
	return (COL(a.r + b.r, a.g + b.g, a.b + b.b));
}

t_color		ft_pro_c(t_color a, t_color b)
{
	return (COL(a.r * b.r, a.g * b.g, a.b * b.b));
}

t_color		ft_add_kc(t_color a, double k)
{
	return (COL(a.r + k, a.g + k, a.b + k));
}

t_color		ft_div_kc(t_color a, double k)
{
	return (COL(a.r / k, a.g / k, a.b / k));
}

t_color		ft_pro_kc(t_color a, double k)
{
	return (COL(a.r * k, a.g * k, a.b * k));
}
