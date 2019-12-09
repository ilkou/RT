/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_moebius.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:35:12 by nhamid            #+#    #+#             */
/*   Updated: 2019/11/22 18:15:48 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static t_vector	normal_moebius(t_vector *hit, t_object *obj)
{
	t_vector	ret;

	ret.v1 = -2 * obj->size * hit->v3 + 2 * hit->v1 * hit->v2 - 4 *
		hit->v1 * hit->v3;
	ret.v2 = (obj->size * obj->size) + hit->v1 * hit->v1 + 3 * hit->v2
		* hit->v2 - 4 * hit->v2 * hit->v3 + hit->v3 * hit->v3;
	ret.v3 = (-2) * obj->size * hit->v1 - 2 * hit->v1 * hit->v1
		- 2 * hit->v2 * hit->v2 + 2 * hit->v2 * hit->v3;
	return (ret);
}

static int		in_moebius(t_object *m, t_vector h)
{
	t_vector	prm;
	double		v;
	double		u;

	v = atan2(h.v2, h.v1);
	u = m->height + 5;
	if (sin(v / 2) != 0.0)
		u = h.v3 / sin(v / 2);
	else if (cos(v) != 0.0 && cos(v / 2) != 0.0)
		u = (h.v1 / cos(v) - m->size) / cos(v / 2);
	else if (sin(v) != 0.0 && cos(v / 2) != 0.0)
		u = (h.v2 / sin(v) - m->size) / cos(v / 2);
	if (!(u >= -m->height && u <= m->height))
		return (0);
	prm.v1 = (m->size + u * cos(v / 2)) * cos(v);
	prm.v2 = (m->size + u * cos(v / 2)) * sin(v);
	prm.v3 = u * sin(v / 2);
	prm = ft_sub(h, prm);
	v = ft_lengthsquared(prm);
	if (v > 0.00001 || v < -0.00001)
		return (0);
	return (1);
}

static void		init_moebius(t_ray *r, t_moebius m, double c[4])
{
	m.ax = r->origin.v1;
	m.ay = r->origin.v2;
	m.az = r->origin.v3;
	m.bx = r->dir.v1;
	m.by = r->dir.v2;
	m.bz = r->dir.v3;
	c[0] = m.ay * m.ay * m.ay - 2 * m.ay * m.ay * m.az + m.ax * m.ax * m.ay
		+ m.ay * m.az * m.az - m.ay * m.a * m.a - 2 * m.ax * m.ax * m.az
		- 2 * m.ax * m.az * m.a;
	c[1] = 3 * m.by * m.ay * m.ay - 4 * m.by * m.ay * m.az - 2 * m.bz * m.ay
		* m.ay + 2 * m.bx * m.ax * m.ay + 2 * m.bz * m.ay * m.az + m.by
		* m.ax * m.ax + m.by * m.az * m.az - m.by * m.a * m.a
		- 4 * m.bx * m.ax * m.az - 2 * m.bz * m.ax * m.ax
		- 2 * m.bz * m.ax * m.a - 2 * m.bx * m.az * m.a;
	c[2] = 3 * m.by * m.by * m.ay - 2 * m.by * m.by * m.az
		+ m.bx * m.bx * m.ay + m.bz * m.bz * m.ay
		+ 2 * m.bx * m.by * m.ax + 2 * m.by * m.bz * m.az
		- 4 * m.bx * m.bz * m.ax - 2 * m.bx * m.bz * m.a
		- 2 * m.bx * m.bx * m.az - 4 * m.by * m.bz * m.ay;
	c[3] = m.by * m.by * m.by + m.bx * m.bx * m.by + m.by * m.bz * m.bz
		- 2 * m.bx * m.bx * m.bz - 2 * m.by * m.by * m.bz;
}

int				ft_hit_moebius(t_object *o, t_ray *ray, t_interval t, t_hit *r)
{
	t_moebius	m;
	double		c[4];
	double		s[3];
	int			x[3];

	x[0] = -1;
	x[2] = 0;
	m.a = o->size;
	init_moebius(ray, m, c);
	if ((x[1] = ft_solve_cubic(c, s)))
	{
		while (++x[0] < x[1])
			if (s[x[0]] > t.t_min && s[x[0]] < t.t_max)
				if (in_moebius(o, ft_ray_function(ray, s[x[0]])))
				{
					x[2] = 1;
					t.t_max = s[x[0]];
					r->t = s[x[0]];
					r->p = ft_ray_function(ray, r->t);
					r->n = ft_normalize(normal_moebius(&r->p, o));
				}
		return (x[2] == 1);
	}
	return (0);
}
