/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vects_ijk_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:47:12 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:11:03 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_rot_ijk(t_r ft_r, double t, t_object *o)
{
	o->i = ft_r(o->i, t);
	o->j = ft_r(o->j, t);
}

void		ft_vects_1(t_object *o)
{
	if (o->rot.v1 == 0 && o->rot.v2 == 0 && o->rot.v3 >= 0)
		o->i = ft_rot_x(o->i, 0);
	else if (o->rot.v1 == 0 && o->rot.v2 == 0 && o->rot.v3 < 0)
		ft_rot_ijk(ft_rot_x, DEG_TO_RAD(180), o);
	else if (o->rot.v1 == 0 && o->rot.v2 >= 0 && o->rot.v3 == 0)
		ft_rot_ijk(ft_rot_x, DEG_TO_RAD(-90), o);
	else if (o->rot.v1 == 0 && o->rot.v2 < 0 && o->rot.v3 == 0)
		ft_rot_ijk(ft_rot_x, DEG_TO_RAD(90), o);
	else if (o->rot.v1 >= 0 && o->rot.v2 == 0 && o->rot.v3 == 0)
		ft_rot_ijk(ft_rot_y, DEG_TO_RAD(-90), o);
	else if (o->rot.v1 < 0 && o->rot.v2 == 0 && o->rot.v3 == 0)
		ft_rot_ijk(ft_rot_y, DEG_TO_RAD(90), o);
	else
		ft_vects_2(o);
}

void		ft_vects_2(t_object *o)
{
	if (o->rot.v1 == 0 && o->rot.v2 != 0 && o->rot.v3 != 0)
		ft_rot_ijk(ft_rot_x, ft_yz_angle(o->rot), o);
	else if (o->rot.v1 != 0 && o->rot.v2 == 0 && o->rot.v3 != 0)
		ft_rot_ijk(ft_rot_y, ft_xz_angle(o->rot), o);
	else if (o->rot.v1 != 0 && o->rot.v2 != 0 && o->rot.v3 == 0)
	{
		o->i = VEC(0, 0, -1);
		o->j = VEC(0, 1, 0);
		o->j = ft_rot_z(o->j, ft_xy_angle(o->rot));
	}
	else
	{
		ft_rot_ijk(ft_rot_x, ft_yz_angle(o->rot), o);
		ft_rot_ijk(ft_rot_y, ft_xz_angle(o->rot), o);
	}
}

void		ft_fin(t_object *o)
{
	double	t;

	t = (DEG_TO_RAD(90.0) - acos(ft_dot(o->rot, o->j) / (ft_length(o->rot)
					* ft_length(o->j))));
	if (o->rot.v3 > 0.0)
		t *= -1.0;
	o->j = ft_rot_vec(o->j, o->i, t);
	o->k = o->rot;
}
