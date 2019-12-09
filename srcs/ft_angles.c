/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:30:53 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/11/17 17:31:03 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_rot_vec(t_vector a, t_vector b, double t)
{
	t_vector	res;

	res.v1 = (b.v1 * b.v1 + (1.0 - b.v1 * b.v1) * cos(t)) * a.v1 + (b.v1 * b.v2
			* (1.0 - cos(t)) - b.v3 * sin(t)) * a.v2 + (b.v1 * b.v3
			* (1.0 - cos(t)) + b.v2 * sin(t)) * a.v3;
	res.v2 = (b.v1 * b.v2 * (1.0 - cos(t)) + b.v3 * sin(t)) * a.v1
		+ (b.v2 * b.v2 + (1.0 - b.v2 * b.v2) * cos(t)) * a.v2
		+ (b.v2 * b.v3 * (1.0 - cos(t)) - b.v1 * sin(t)) * a.v3;
	res.v3 = (b.v1 * b.v3 * (1.0 - cos(t)) - b.v2 * sin(t)) * a.v1
		+ (b.v2 * b.v3 * (1.0 - cos(t)) + b.v1 * sin(t)) * a.v2
		+ (b.v3 * b.v3 + (1.0 - b.v3 * b.v3) * cos(t)) * a.v3;
	return (res);
}

double		ft_xz_angle(t_vector v)
{
	if (v.v3 > 0)
		return (atan(v.v1 / v.v3));
	else if (v.v1 > 0 && v.v3 < 0)
		return (DEG_TO_RAD(90) + atan(-v.v3 / v.v1));
	else if (v.v1 < 0 && v.v3 < 0)
		return (-DEG_TO_RAD(90) - atan(v.v3 / v.v1));
	return (0);
}

double		ft_yz_angle(t_vector v)
{
	if (v.v3 > 0)
		return (-atan(v.v2 / v.v3));
	else if (v.v2 > 0 && v.v3 < 0)
		return (DEG_TO_RAD(90) + atan(-v.v3 / v.v2));
	else if (v.v3 < 0 && v.v2 < 0)
		return (-DEG_TO_RAD(90) - atan(v.v3 / v.v2));
	return (0);
}

double		ft_xy_angle(t_vector v)
{
	if (v.v2 > 0)
		return (atan(v.v1 / v.v2));
	else if (v.v2 < 0 && v.v1 < 0)
		return (-DEG_TO_RAD(90) - atan(-v.v2 / v.v1));
	else if (v.v2 < 0 && v.v1 > 0)
		return (DEG_TO_RAD(90) + atan(-v.v2 / v.v1));
	return (0);
}
