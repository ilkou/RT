/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:17:43 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/21 17:17:52 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				ft_shading(t_scene *scene, t_vector lpos, t_light *l)
{
	t_object	*obj;
	t_ray		r;
	t_hit		rec;
	double		closest_so_far;

	obj = scene->object;
	if (l->type == P_LIGHT)
		r.dir = ft_sub(lpos, scene->record.p);
	else
		r.dir = ft_pro_k(l->dir, -1);
	closest_so_far = l->type == P_LIGHT ? ft_length(r.dir) : 8000.0;
	r.origin = scene->record.p;
	r.dir = ft_normalize(r.dir);
	while (obj != NULL)
	{
		if (obj != scene->record.curr_obj)
			if (ft_hit(scene, r, I(0.0001, closest_so_far), &rec))
				return (1);
		obj = obj->next;
	}
	return (0);
}
