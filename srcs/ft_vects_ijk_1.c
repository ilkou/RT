/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vects_ijk_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:47:06 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/12/09 17:37:48 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_plane_ijk(t_object *obj)
{
	if (obj->size < 0)
		obj->size = INFINITY;
	if (obj->height < 0)
		obj->height = INFINITY;
}

void		ft_triangle_ijk(t_object *obj)
{
	obj->j = ft_rot_vec(obj->i, obj->rot, DEG_TO_RAD(120));
	obj->k = ft_rot_vec(obj->i, obj->rot, DEG_TO_RAD(-120));
}

void		ft_cylinder_ijk(t_object *obj)
{
	ft_add_conts(obj, ft_pro_k(obj->i, 0.0), 0, obj);
	if (obj->weight == 1.0)
		ft_add_conts(obj->cont, ft_pro_k(obj->i, 0.0), 3, obj);
	if (obj->weight == 2.0)
	{
		ft_add_conts(obj->cont, ft_pro_k(obj->i, -obj->size / 2.0), 3, obj);
		ft_add_conts(obj->cont->cont,
				ft_pro_k(obj->j, -obj->size / 2.0), 4, obj);
		obj->cont->cont->height /= 2;
		obj->cont->cont->cont->height /= 2;
		if (obj->cont->cont->cont->size < 0)
			obj->cont->cont->cont->size = INFINITY;
		if (obj->cont->cont->cont->height < 0)
			obj->cont->cont->cont->height = INFINITY;
	}
	if (obj->cont->cont->size < 0)
		obj->cont->cont->size = INFINITY;
	if (obj->cont->cont->height < 0)
		obj->cont->cont->height = INFINITY;
	obj->hit = ft_hit_cube;
	obj->cont->hit = ft_hit_cylinder;
}

void		ft_vects(t_object *obj)
{
	obj->i = VEC(1, 0, 0);
	obj->j = VEC(0, 1, 0);
	obj->k = VEC(0, 0, 1);
	ft_vects_1(obj);
	ft_fin(obj);
	if (ft_strcmp(obj->name, "PLANE") == 0)
		ft_plane_ijk(obj);
	if (ft_strcmp(obj->name, "TRIANGLE") == 0)
		ft_triangle_ijk(obj);
	if (ft_strcmp(obj->name, "CUBE") == 0)
		ft_cube_ijk(obj);
	if (ft_strcmp(obj->name, "CYLINDER") == 0)
	{
		if (obj->weight == 1.0 || obj->weight == 2.0)
			ft_cylinder_ijk(obj);
	}
}
