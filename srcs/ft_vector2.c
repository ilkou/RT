/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:54:32 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/15 18:35:16 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_normalize(t_vector a)
{
	float k;

	if (a.v1 == 0.0 && a.v2 == 0.0 && a.v3 == 0.0)
		return (VEC(0, 1, 0));
	k = 1.0 / sqrt(a.v1 * a.v1 + a.v2 * a.v2 + a.v3 * a.v3);
	return (ft_pro_k(a, k));
}

t_vector	ft_pro_k(t_vector a, double k)
{
	return (VEC(a.v1 * k, a.v2 * k, a.v3 * k));
}

t_vector	ft_div_k(t_vector a, double k)
{
	return (VEC(a.v1 / k, a.v2 / k, a.v3 / k));
}

double		ft_dot(t_vector a, t_vector b)
{
	return (a.v1 * b.v1 + a.v2 * b.v2 + a.v3 * b.v3);
}

t_vector	ft_cross(t_vector a, t_vector b)
{
	return (VEC((a.v2 * b.v3 - a.v3 * b.v2), -(a.v1 * b.v3 - a.v3 * b.v1),
				(a.v1 * b.v2 - a.v2 * b.v1)));
}
