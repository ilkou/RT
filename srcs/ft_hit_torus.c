/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_torus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:10:59 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/12/02 21:22:53 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector		normal_torus(const t_object obj, const t_vector hit_point)
{
	float		k;
	t_vector	a;
	t_vector	normal;

	k = ft_dot(ft_sub(hit_point, obj.pos), obj.rot);
	a = ft_sub(hit_point, ft_pro_k(obj.rot, k));
	normal = ft_sub(a, obj.pos);
	normal = ft_normalize(normal);
	normal = ft_add(obj.pos, ft_pro_k(normal, obj.size));
	normal = ft_sub(hit_point, normal);
	return (ft_normalize(normal));
}

static void		ft_norm(t_object *obj, t_ray *ray, t_hit *rrr, t_var *var)
{
	var->i = 0;
	var->a = 0;
	var->m = 1 - pow(ft_dot(obj->rot, ray->dir), 2);
	var->n = 2 * (ft_dot(rrr->oc, ray->dir) - ft_dot(obj->rot, rrr->oc)
			* ft_dot(obj->rot, ray->dir));
	var->o = ft_dot(rrr->oc, rrr->oc) - pow(ft_dot(obj->rot, rrr->oc), 2);
	var->p = ft_dot(rrr->oc, rrr->oc) + obj->size
		* obj->size - obj->height * obj->height;
}

static void		ft_torus_uv(double size, t_hit *rrr)
{
	rrr->u = 0.5 + atan2(rrr->d.v3, rrr->d.v1) / (2.0 * M_PI);
	rrr->v = 0.5 + atan2(rrr->d.v2, (pow((rrr->d.v1 * rrr->d.v1 + rrr->d.v3
						* rrr->d.v3), 0.5) - size)) / (2.0 * M_PI);
}

static int		ft_norm1(double c[5], t_object *obj, t_hit *rrr, t_var var)
{
	double	s[4];

	if ((var.k = ft_solve_quartic(c, s)))
	{
		while (var.i < var.k)
		{
			if (s[var.i] > var.t.t_min && s[var.i] < var.t.t_max)
			{
				var.a = 1;
				var.t.t_max = s[var.i];
				rrr->t = s[var.i];
				rrr->p = ft_ray_function(var.ray, rrr->t);
				rrr->n = normal_torus(*obj, rrr->p);
				rrr->d = ft_div_k(ft_sub(rrr->p, obj->pos), obj->txt.scale);
				rrr->d = VEC(ft_dot(rrr->d, obj->i), ft_dot(rrr->d, obj->k),
						ft_dot(rrr->d, obj->j));
				ft_torus_uv(obj->size, rrr);
			}
			var.i += 1;
		}
		if (var.a == 1)
			return (1);
	}
	return (0);
}

int				ft_hit_torus(t_object *obj, t_ray *ray,
		t_interval t, t_hit *rrr)
{
	t_var	var;
	double	c[5];

	rrr->oc = ft_sub(ray->origin, obj->pos);
	ft_norm(obj, ray, rrr, &var);
	c[4] = 1;
	c[3] = 4 * ft_dot(rrr->oc, ray->dir);
	c[2] = 2 * var.p + c[3] * c[3] * 0.25 - 4 * var.m * obj->size * obj->size;
	c[1] = c[3] * var.p - 4 * var.n * obj->size * obj->size;
	c[0] = var.p * var.p - 4 * obj->size * obj->size * var.o;
	var.t = t;
	var.ray = ray;
	return (ft_norm1(c, obj, rrr, var));
}
