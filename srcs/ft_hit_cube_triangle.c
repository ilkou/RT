/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_cube_triangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:27:56 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/12/02 21:35:11 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				ft_hit_triangle(t_object *o, t_ray *r, t_interval t, t_hit *rrr)
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
	if (ft_dot(ft_sub(rec.p, o->pos), o->i) * 2 > o->size
			|| ft_dot(ft_sub(rec.p, o->pos), o->j) * 2 > o->size
			|| ft_dot(ft_sub(rec.p, o->pos), o->k) * 2 > o->size)
		return (0);
	return (ft_fix_rec(rrr, &rec));
}

int				ft_hit_cube(t_object *o, t_ray *r, t_interval t, t_hit *rec)
{
	t_object	*tt;
	double		closest_so_far;
	int			hit_anything;

	hit_anything = 0;
	closest_so_far = t.t_max;
	tt = o;
	o = o->cont;
	while (o)
	{
		if (o->hit(o, r, I(t.t_min, closest_so_far), rec))
		{
			hit_anything = 1;
			closest_so_far = rec->t;
			rec->col = o->col;
			rec->hit = o->hit;
			rec->curr_obj = tt;
			rec->ray = *r;
		}
		o = o->cont;
	}
	return (hit_anything);
}

void			ft_add_conts(t_object *o, t_vector r, int x, t_object *tete)
{
	if (!(o->cont = (struct s_o *)malloc(sizeof(struct s_o))))
		ft_perror_exit();
	o->cont->pos.v1 = tete->pos.v1 + r.v1;
	o->cont->pos.v2 = tete->pos.v2 + r.v2;
	o->cont->pos.v3 = tete->pos.v3 + r.v3;
	o->cont->rotaxis = o->rotaxis;
	o->cont->col = o->col;
	o->cont->hit = ft_hit_plane;
	o->cont->ex_rot = o->ex_rot;
	o->cont->name = ft_strdup(o->name);
	ft_detect(o->cont, tete, x);
	o->cont->cont = NULL;
	o->cont->next = NULL;
}

void			ft_detect(t_object *new, t_object *old, int x)
{
	if (x == 0)
		new = zero_x_case(new, old);
	else if (x == 1)
		new = one_x_case(new, old);
	else if (x == 2)
		new = two_x_case(new, old);
	else if (x == 3)
		new = three_x_case(new, old);
	else if (x == 4)
		new = four_x_case(new, old);
}
