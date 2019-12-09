/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specular.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:57 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 18:23:27 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static double	phong(t_scene *s, t_vector v)
{
	t_vector	reflected;
	t_object	*obj;
	double		spec;

	spec = 0.0;
	obj = s->record.curr_obj;
	v = ft_normalize(v);
	reflected = ft_reflect(v, s->record.n);
	reflected = ft_normalize(reflected);
	spec = pow(ffmax(ft_dot(reflected, s->record.ray.dir), 0.0), obj->ke);
	return (spec);
}

static double	blinn_phong(t_scene *s, t_vector v)
{
	t_vector	blinn_dir;
	t_object	*obj;
	double		spec;

	spec = 0.0;
	obj = s->record.curr_obj;
	v = ft_normalize(v);
	blinn_dir = ft_sub(v, s->record.ray.dir);
	if (sqrt(ft_dot(blinn_dir, blinn_dir)) != 0.0)
	{
		blinn_dir = ft_div_k(blinn_dir, sqrt(ft_dot(blinn_dir, blinn_dir)));
		spec = pow(ffmax(ft_dot(blinn_dir, s->record.n), 0.0), obj->ke);
	}
	return (spec);
}

t_color			specular(t_scene *s, t_light *l)
{
	t_vector	light_vec;
	t_object	*obj;
	t_color		c;
	double		spec;

	obj = s->record.curr_obj;
	if (l->type == P_LIGHT)
		light_vec = ft_sub(l->pos, s->record.p);
	else
		light_vec = ft_pro_k(l->dir, -1);
	if (obj->spec == PHONG)
		spec = phong(s, light_vec);
	else
		spec = blinn_phong(s, light_vec);
	c = ft_pro_kc(ft_pro_c(COL(0.9, 0.9, 0.9), l->col), spec);
	return (c);
}
