/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:43:55 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/15 18:34:56 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_vector(double x, double y, double z)
{
	t_vector v;

	v.v1 = x;
	v.v2 = y;
	v.v3 = z;
	return (v);
}

t_vector	ft_add(t_vector a, t_vector b)
{
	return (VEC(a.v1 + b.v1, a.v2 + b.v2, a.v3 + b.v3));
}

t_vector	ft_sub(t_vector a, t_vector b)
{
	return (VEC(a.v1 - b.v1, a.v2 - b.v2, a.v3 - b.v3));
}

t_vector	ft_div(t_vector a, t_vector b)
{
	return (VEC(a.v1 / b.v1, a.v2 / b.v2, a.v3 / b.v3));
}

t_vector	ft_pro(t_vector a, t_vector b)
{
	return (VEC(a.v1 * b.v1, a.v2 * b.v2, a.v3 * b.v3));
}
