/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:45:57 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:28:42 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static int		ft_check_plane(t_object *o, t_hit rec)
{
	if (fabs(ft_dot(ft_sub(rec.p, o->pos), o->i)) > o->size
			|| fabs(ft_dot(ft_sub(rec.p, o->pos), o->j)) > o->height ||
			(o->name && ft_strcmp(o->name, "PLANE") == 0
			&& ((o->weight > 0
			&& fabs(ft_dot(ft_sub(rec.p, o->pos), o->i)) < o->weight
			&& fabs(ft_dot(ft_sub(rec.p, o->pos), o->j)) < o->weight)
			|| (o->weight < 0
			&& ft_length(ft_sub(rec.p, o->pos)) < -o->weight))))
		return (1);
	return (0);
}

int				ft_hit_plane(t_object *o, t_ray *r, t_interval t, t_hit *rrr)
{
	t_hit rec;

	if (ft_dot(o->rot, r->dir) == 0)
		return (0);
	rec.t = ft_dot(o->rot, ft_sub(o->pos, r->origin))
		/ ft_dot(o->rot, r->dir);
	if (rec.t >= t.t_max || rec.t <= t.t_min)
		return (0);
	if (ft_dot(r->dir, o->rot) > 0)
		rec.n = ft_pro_k(o->rot, -1.0);
	else
		rec.n = o->rot;
	rec.p = ft_ray_function(r, rec.t);
	if (ft_check_plane(o, rec))
		return (0);
	ft_plane_mapping(&rec, o);
	rec.surface = IS_PLANE;
	rec.i = o->i;
	rec.j = o->j;
	return (ft_fix_rec(rrr, &rec));
}
