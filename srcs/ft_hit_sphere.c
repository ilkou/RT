/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:21:59 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/05 00:12:38 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		ft_sphere_uv(t_object *o, t_hit *rec, t_vector p)
{
	double	phi;
	double	theta;

	p = ft_div_k(VEC(ft_dot(p, o->i), ft_dot(p, o->j), ft_dot(p, o->k)),
			o->txt.scale);
	phi = atan2(p.v3, p.v1);
	theta = asin(p.v2);
	if (ft_dot(o->k, VEC(0, 0, -1)) >= 0.0)
		rec->u = (phi + M_PI) / (2.0 * M_PI);
	else
		rec->u = 1 - (phi + M_PI) / (2.0 * M_PI);
	rec->v = (theta + M_PI / 2.0) / M_PI;
	return (1);
}

static int		ft_ret_sphere(t_object *o, t_ray *r, t_interval t, t_hit *rec)
{
	t_hit rrr;

	if (rec->t0 < t.t_max && rec->t0 > t.t_min)
	{
		rrr.t = rec->t0;
		rrr.p = ft_ray_function(r, rrr.t);
		rrr.n = ft_normalize(ft_sub(rrr.p, o->pos));
		if (o->height == 0.0 || ft_dot(rrr.n, o->rot) > 0.0)
			return (ft_fix_rec(rec, &rrr));
		else
		{
			rrr.cap.weight = 0.0;
			rrr.cap.pos = o->pos;
			rrr.cap.size = o->size;
			rrr.cap.rot = ft_pro_k(o->rot, -1.0);
			rrr.cap.name = NULL;
			if (ft_hit_disk(&rrr.cap, r, t, &rrr))
				return (ft_fix_rec(rec, &rrr));
		}
	}
	return (0);
}

int				ft_hit_sphere(t_object *o, t_ray *r, t_interval t, t_hit *rrr)
{
	t_hit rec;

	rec.oc = ft_sub(r->origin, o->pos);
	rec.a = ft_dot(r->dir, r->dir);
	rec.b = 2 * ft_dot(rec.oc, r->dir);
	rec.c = ft_dot(rec.oc, rec.oc) - (o->size * o->size);
	rec.delta = rec.b * rec.b - 4 * rec.a * rec.c;
	if (rec.delta <= 0)
		return (0);
	rec.t0 = (-rec.b - sqrt(rec.delta)) / (2 * rec.a);
	rec.t1 = (-rec.b + sqrt(rec.delta)) / (2 * rec.a);
	if (rec.t0 > rec.t1)
		ft_swap_d(&rec.t0, &rec.t1);
	if (rec.t0 < t.t_min || rec.t0 > t.t_max)
		ft_swap_d(&rec.t0, &rec.t1);
	if (ft_ret_sphere(o, r, t, &rec) && ft_sphere_uv(o, &rec, rec.n))
		return (ft_fix_rec(rrr, &rec));
	return (0);
}
