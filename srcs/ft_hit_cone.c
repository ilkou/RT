/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:00:57 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:31:34 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int			ft_cap(t_object *o, t_object *cap, double k, double up_down)
{
	*cap = *o;
	cap->size = k * tan(o->size);
	cap->rot = ft_pro_k(o->rot, up_down);
	cap->pos = ft_add(o->pos, ft_pro_k(o->rot, up_down * k));
	cap->name = NULL;
	cap->weight = 0.0;
	cap->height = 0.0;
	return (1);
}

static int			ft_ret_cone_norm(t_hit *rec, t_ray *r, t_object *o)
{
	rec->t = rec->t0;
	rec->p = ft_ray_function(r, rec->t);
	rec->temp = ft_pro_k(o->rot, (ft_dot(r->dir, o->rot)
				* rec->t + ft_dot(rec->oc, o->rot)));
	rec->temp = ft_pro_k(rec->temp, (1 + pow(tan(o->size), 2)));
	rec->n = ft_normalize(ft_sub(ft_sub(rec->p, o->pos), rec->temp));
	rec->d = ft_sub(rec->p, o->pos);
	rec->d = VEC(ft_dot(rec->d, o->i), ft_dot(rec->d, o->j),
			ft_dot(rec->d, o->k));
	rec->d = ft_div_k(rec->d, (o->height > 0 ? o->height : 50)
			* o->txt.scale);
	rec->u = atan2(rec->d.v2, rec->d.v1) / M_PI;
	rec->v = rec->d.v3;
	rec->u = rec->u - floor(rec->u);
	rec->v = rec->v - floor(rec->v);
	return (1);
}

static int			ft_ret_cone(t_object *o, t_ray *r, t_interval t, t_hit *rec)
{
	t_hit			rec2;
	t_hit			rec3;
	int				hit_anything;

	hit_anything = 0;
	ft_cap(o, &rec2.cap, o->height, 1.0);
	ft_cap(o, &rec3.cap, o->weight, -1.0);
	if ((rec->t0 < t.t_min || rec->t0 > t.t_max))
		return (0);
	if ((o->height <= 0.0 && o->weight <= 0.0) || ((rec->m0 > -o->weight
					&& rec->m0 < o->height) && (t.t_max = rec->t0)))
		hit_anything = ft_ret_cone_norm(rec, r, o);
	if (o->height > 0.0 && ft_hit_disk(&rec2.cap, r, t, &rec2)
			&& (t.t_max = rec2.t))
		hit_anything = ft_fix_rec(rec, &rec2);
	if (o->weight > 0.0 && ft_hit_disk(&rec3.cap, r, t, &rec3))
		hit_anything = ft_fix_rec(rec, &rec3);
	return (hit_anything);
}

int					ft_hit_cone(t_object *o, t_ray *r, t_interval t, t_hit *rrr)
{
	t_hit			rec;

	rec.oc = ft_sub(r->origin, o->pos);
	rec.a = ft_dot(r->dir, r->dir) - (1 + pow(tan(o->size), 2))
		* pow(ft_dot(r->dir, o->rot), 2);
	rec.b = 2 * (ft_dot(r->dir, rec.oc) - (1 + pow(tan(o->size), 2))
			* ft_dot(r->dir, o->rot) * ft_dot(rec.oc, o->rot));
	rec.c = ft_dot(rec.oc, rec.oc) - (1 + pow(tan(o->size), 2))
		* pow(ft_dot(rec.oc, o->rot), 2);
	rec.delta = rec.b * rec.b - 4 * rec.a * rec.c;
	if (rec.delta < 0)
		return (0);
	rec.t0 = (-rec.b - sqrt(rec.delta)) / (2 * rec.a);
	rec.t1 = (-rec.b + sqrt(rec.delta)) / (2 * rec.a);
	if (rec.t0 > rec.t1)
		ft_swap_d(&rec.t0, &rec.t1);
	if ((rec.t0 < t.t_min || rec.t0 > t.t_max))
		ft_swap_d(&rec.t0, &rec.t1);
	rec.m0 = ft_dot(r->dir, o->rot) * rec.t0 + ft_dot(rec.oc, o->rot);
	rec.m1 = ft_dot(r->dir, o->rot) * rec.t1 + ft_dot(rec.oc, o->rot);
	if (ft_ret_cone(o, r, t, &rec))
		return (ft_fix_rec(rrr, &rec));
	return (0);
}
