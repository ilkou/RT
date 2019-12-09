/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:36:10 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 14:49:42 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double		ft_length(t_vector a)
{
	return (sqrt(a.v1 * a.v1 + a.v2 * a.v2 + a.v3 * a.v3));
}

double		ft_lengthsquared(t_vector a)
{
	return (a.v1 * a.v1 + a.v2 * a.v2 + a.v3 * a.v3);
}

double		ft_angle_between(t_vector a, t_vector b)
{
	return (acos(ft_dot(a, b) / (ft_length(a) * ft_length(b))));
}

t_vector	ft_vfloor(t_vector v)
{
	return (VEC(floor(v.v1), floor(v.v2), floor(v.v3)));
}

t_vector	ft_vabs(t_vector v)
{
	return (VEC(fabs(v.v1), fabs(v.v2), fabs(v.v3)));
}
