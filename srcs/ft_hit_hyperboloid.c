/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_hyperboloid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:27:28 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 19:56:01 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int		ft_hit_hyperboloid(t_object *o, t_ray *ray, t_interval t, t_hit *r)
{
	t_hit		v;
	t_vector	c;

	v.d = ray->dir;
	c = ray->origin;
	v.a = v.d.v3 * v.d.v3 - v.d.v1 * v.d.v1 - v.d.v2 * v.d.v2;
	v.b = 2 * (c.v3 * v.d.v3 - c.v1 * v.d.v1 - c.v2 * v.d.v2);
	v.c = c.v3 * c.v3 + o->size - c.v1 * c.v1 - c.v2 * c.v2;
	v.delta = v.b * v.b - 4 * v.a * v.c;
	if (v.delta < 0)
		return (0);
	v.t0 = (-v.b - sqrt(v.delta)) / (2 * v.a);
	v.t1 = (-v.b + sqrt(v.delta)) / (2 * v.a);
	if (v.t0 > v.t1)
		ft_swap_d(&v.t0, &v.t1);
	if (v.t0 < t.t_min || v.t0 > t.t_max)
		ft_swap_d(&v.t0, &v.t1);
	if (v.t0 > t.t_max || v.t0 < t.t_min)
		return (0);
	r->t = v.t0;
	r->p = ft_ray_function(ray, r->t);
	r->n = ft_normalize(VEC(2 * r->p.v1, 2 * r->p.v2, -2 * r->p.v3));
	return (1);
}
