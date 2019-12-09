/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:22:32 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 18:08:33 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		ft_init_cap(t_object *o, t_object *cap, int up_down)
{
	cap->rot = ft_pro_k(o->rot, up_down);
	cap->pos = ft_add(o->pos, ft_pro_k(o->rot, up_down * o->height));
	cap->weight = o->weight;
	cap->j = o->j;
	cap->i = o->i;
	cap->size = o->size;
	cap->name = NULL;
	cap->txt.scale = o->txt.scale;
	return (1);
}

static t_hit	ft_ret_cylinder_n(t_hit *rrr, t_ray *r, t_object *o, t_hit rec)
{
	rec.t = rrr->t0;
	rec.p = ft_ray_function(r, rec.t);
	rec.n = ft_normalize(ft_sub(ft_sub(rec.p, o->pos),
				ft_pro_k(o->rot, ft_dot(r->dir, o->rot)
					* rec.t + ft_dot(rrr->oc, o->rot))));
	return (rec);
}

static t_hit	ft_ret_cylinder_n1(t_object *o, t_hit rec)
{
	rec.d = ft_div_k(ft_sub(rec.p, o->pos), o->txt.scale
	* (o->height <= 0 ? -1 : o->height) * 5.0);
	rec.d = VEC(ft_dot(rec.d, o->i), ft_dot(rec.d, o->k), ft_dot(rec.d, o->j));
	rec.u = (atan2(rec.d.v1, rec.d.v3) / (2.0 * M_PI));
	rec.v = rec.d.v2 * (o->height <= 0 ? -1 : o->height) / 2.0;
	rec.u = rec.u - floor(rec.u);
	rec.v = rec.v - floor(rec.v);
	return (rec);
}

static int		ft_ret_cylinder(t_object
		*o, t_ray *r, t_interval t, t_hit *rrr)
{
	t_hit	rec;

	if (o->height > 0.0 && rrr->m0 < -o->height && rrr->m1 > -o->height
			&& ft_init_cap(o, &rec.cap, -1))
		return (ft_hit_disk(&rec.cap, r, t, rrr));
	else if (o->height <= 0.0
			|| (rrr->m0 >= -o->height && rrr->m0 <= o->height))
	{
		if ((rrr->t0 < t.t_min || rrr->t0 > t.t_max))
			return (0);
		rec = ft_ret_cylinder_n(rrr, r, o, rec);
		if (o->weight == 1.0 && ft_dot(ft_sub(rec.p, o->pos), o->j) >= 0)
			return (0);
		if (o->weight == 2.0 && (ft_dot(ft_sub(rec.p, o->pos),
						o->j) >= 0 || ft_dot(ft_sub(rec.p, o->pos), o->i) >= 0))
			return (0);
		rec = ft_ret_cylinder_n1(o, rec);
		return (ft_fix_rec(rrr, &rec));
	}
	else if (o->height > 0.0 && rrr->m0 > o->height && rrr->m1 < o->height
			&& ft_init_cap(o, &rec.cap, 1))
		return (ft_hit_disk(&rec.cap, r, t, rrr));
	return (0);
}

int				ft_hit_cylinder(t_object *o, t_ray *r, t_interval t, t_hit *rec)
{
	rec->cap.size = o->size;
	rec->oc = ft_sub(r->origin, o->pos);
	rec->a = ft_dot(r->dir, r->dir) - pow(ft_dot(r->dir, o->rot), 2);
	rec->b = 2 * (ft_dot(r->dir, rec->oc) - (ft_dot(r->dir, o->rot)
				* ft_dot(rec->oc, o->rot)));
	rec->c = ft_dot(rec->oc, rec->oc) - pow(ft_dot(rec->oc, o->rot), 2)
		- o->size * o->size;
	rec->delta = rec->b * rec->b - 4 * rec->a * rec->c;
	if (rec->delta < 0)
		return (0);
	rec->t0 = (-rec->b - sqrt(rec->delta)) / (2 * rec->a);
	rec->t1 = (-rec->b + sqrt(rec->delta)) / (2 * rec->a);
	rec->d = ft_pro_k(o->rot,
			fabs(ft_dot(o->rot, rec->oc) / ft_dot(o->rot, o->rot)));
	if (rec->t0 > rec->t1)
		ft_swap_d(&rec->t0, &rec->t1);
	if (ft_length(rec->d) <= o->height &&
			ft_length(ft_sub(rec->oc, rec->d)) <= o->size)
		ft_swap_d(&rec->t0, &rec->t1);
	if ((o->height <= 0.0 && (rec->t0 < t.t_min || rec->t0 > t.t_max)))
		ft_swap_d(&rec->t0, &rec->t1);
	rec->m0 = ft_dot(r->dir, o->rot) * rec->t0 + ft_dot(rec->oc, o->rot);
	rec->m1 = ft_dot(r->dir, o->rot) * rec->t1 + ft_dot(rec->oc, o->rot);
	return (ft_ret_cylinder(o, r, t, rec));
}
