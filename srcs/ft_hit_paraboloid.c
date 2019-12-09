/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marrin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:38:44 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/19 23:11:12 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_hit_paraboloid(t_object *o, t_ray *ray, t_interval t, t_hit *rrr)
{
	t_hit r;

	r.oc = ft_sub(ray->origin, o->pos);
	r.a = ft_dot(ray->dir, ray->dir) - pow(ft_dot(ray->dir, o->rot), 2);
	r.b = 2 * (ft_dot(ray->dir, r.oc) - ft_dot(ray->dir, o->rot)
			* (ft_dot(r.oc, o->rot) + 2 * o->size));
	r.c = ft_dot(r.oc, r.oc) - ft_dot(r.oc, o->rot)
		* (ft_dot(r.oc, o->rot) + 4 * o->size);
	r.delta = r.b * r.b - (4 * r.a * r.c);
	if (r.delta < 0)
		return (0);
	r.t0 = (-r.b - sqrt(r.delta)) / (2 * r.a);
	r.t1 = (-r.b + sqrt(r.delta)) / (2 * r.a);
	if (r.t0 > r.t1)
		ft_swap_d(&r.t0, &r.t1);
	if (r.t0 < t.t_min || r.t0 > t.t_max)
		ft_swap_d(&r.t0, &r.t1);
	if (r.t0 > t.t_max || r.t0 < t.t_min)
		return (0);
	r.m0 = ft_dot(ray->dir, o->rot) * r.t0 + ft_dot(r.oc, o->rot);
	rrr->t = r.t0;
	rrr->p = ft_ray_function(ray, rrr->t);
	rrr->n = ft_sub(ft_sub(rrr->p, o->pos), ft_pro_k(o->rot, r.m0 + o->size));
	rrr->n = ft_normalize(rrr->n);
	return (1);
}
