/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:41:21 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/21 17:31:52 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static void		point_light(t_scene *s, t_light *l, t_color *d, t_color *spec)
{
	t_object	*obj;
	t_light		tmp;
	int			k;
	int			in;

	obj = s->record.curr_obj;
	k = -1;
	while (++k < l->soft.x)
	{
		tmp = *l;
		tmp.pos = l->soft.x > 1 ? ft_rand_in_sphere(l->pos, l->soft.y) : l->pos;
		l->angle = ft_angle_between(ft_sub(tmp.pos, s->record.p), l->dir);
		in = !ft_shading(s, tmp.pos, &tmp)
			&& RAD_TO_DEG(l->angle) < l->flashlight ? 0 : 1;
		*d = !in ? ft_add_c(*d, diffuse(s, &tmp)) : *d;
		*spec = !in && obj->hit != HIT_P ?
			ft_add_c(*spec, specular(s, &tmp)) : *spec;
	}
	*d = ft_div_kc(*d, l->soft.x);
	*spec = ft_div_kc(*spec, l->soft.x);
}

static t_object	*init_phong(t_scene *p, t_phong *phong, t_color *col)
{
	phong->ambient = COL(0, 0, 0);
	phong->diffuse = COL(0, 0, 0);
	phong->specular = COL(0, 0, 0);
	if (p->light == NULL)
	{
		*col = ft_pro_kc(p->record.col, p->amb);
		return (NULL);
	}
	return (p->record.curr_obj);
}

void			ft_lighting(t_scene *s, t_light *l, t_color *col)
{
	t_object	*obj;
	t_phong		p;
	int			in;

	if ((obj = init_phong(s, &p, col)) == NULL)
		return ;
	while (l != NULL)
	{
		if (l->type == P_LIGHT)
			point_light(s, l, &p.diffuse, &p.specular);
		else
		{
			in = ft_shading(s, l->pos, l) ? 1 : 0;
			p.diffuse = !in ? ft_add_c(p.diffuse, diffuse(s, l)) : p.diffuse;
			p.specular = !in ? ft_add_c(p.specular, specular(s, l))
				: p.specular;
		}
		l = l->next;
	}
	p.diffuse = ft_pro_kc(p.diffuse, obj->kd);
	p.specular = ft_pro_kc(p.specular, obj->ks);
	p.ambient = ft_pro_kc(s->record.col, obj->ka);
	*col = ft_add_c(p.ambient, ft_add_c(p.specular, p.diffuse));
}
