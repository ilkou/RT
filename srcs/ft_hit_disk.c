/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:46:52 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 22:48:43 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static int	ft_check_disk(t_object *o, t_hit rec)
{
	if (ft_length(ft_sub(rec.p, o->pos)) > o->size ||
			(o->name && ft_strcmp(o->name, "DISK") == 0
			&& ((o->height > 0
			&& fabs(ft_dot(ft_sub(rec.p, o->pos), o->i)) < o->height
			&& fabs(ft_dot(ft_sub(rec.p, o->pos), o->j)) < o->height)
			|| (o->height < 0
			&& ft_length(ft_sub(rec.p, o->pos)) < -o->height))))
		return (1);
	return (0);
}

int			ft_hit_disk(t_object *o, t_ray *r, t_interval t, t_hit *rrr)
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
	if (ft_check_disk(o, rec))
		return (0);
	if (o->weight == 1.0 && ft_dot(ft_sub(rec.p, o->pos), o->j) > 0.0)
		return (0);
	if (o->weight == 2.0 && (ft_dot(ft_sub(rec.p, o->pos), o->j) > 0.0
				|| ft_dot(ft_sub(rec.p, o->pos), o->i) > 0.0))
		return (0);
	ft_plane_mapping(&rec, o);
	rec.surface = IS_PLANE;
	rec.i = o->i;
	rec.j = o->j;
	return (ft_fix_rec(rrr, &rec));
}
