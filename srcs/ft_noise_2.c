/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noise_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:49:03 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/11/22 17:31:43 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color	ft_get_checkerboard(t_object *o, t_hit *rec, t_noise *noise)
{
	double		pro_i;
	double		pro_j;
	t_vector	d;

	d = ft_sub(o->pos, rec->p);
	if (ft_strcmp(o->name, "SPHERE") == 0)
	{
		pro_i = floor(ft_dot(d, o->j) * noise->scale2);
		pro_j = floor(ft_dot(d, o->i) * noise->scale2);
	}
	else
	{
		pro_i = floor(ft_dot(d, rec->surface == IS_PLANE ?
					rec->i : o->i) * noise->scale2);
		pro_j = floor(ft_dot(d, rec->surface == IS_PLANE ?
					rec->j : o->k) * noise->scale2);
	}
	if ((fmod((pro_i), noise->scale1) == 0.0 && fmod((pro_j),
			noise->scale1) == 0.0) || (fmod((pro_i), noise->scale1) != 0.0
				&& fmod((pro_j), noise->scale1) != 0.0))
		return (noise->col1);
	return (noise->col2);
}

t_color	ft_get_mamamiya(t_object *o, t_hit *rec, t_noise *noise)
{
	double		pro_i;
	t_vector	d;

	d = ft_sub(o->pos, rec->p);
	if (ft_strcmp(o->name, "SPHERE") && o->height == 0
			&& rec->surface == IS_PLANE)
		pro_i = floor(RAD_TO_DEG(acos(ft_dot(d, ft_add(rec->i, rec->j))
				/ (ft_length(ft_add(rec->i, rec->j)) * ft_length(d)))));
	else if (ft_strcmp(o->name, "CYLINDER")
			&& (o->height == 1 || o->height == 2) && rec->surface == IS_PLANE)
		pro_i = floor(RAD_TO_DEG(acos(ft_dot(d, ft_add(rec->i, rec->j))
				/ (ft_length(ft_add(rec->i, rec->j)) * ft_length(d)))));
	else
		pro_i = floor(RAD_TO_DEG(acos(ft_dot(d,
							ft_add(ft_add(o->i, o->j), o->k))
				/ (ft_length(ft_add(ft_add(o->k,
								o->j), o->i)) * ft_length(d)))));
	if (fmod((pro_i), noise->scale1) == 0.0)
		return (noise->col1);
	else
		return (noise->col2);
}

t_color	ft_get_cercles(t_object *o, t_hit *rec, t_noise *noise)
{
	double		pro_i;
	t_vector	d;

	d = ft_sub(o->pos, rec->p);
	pro_i = floor(ft_length(d));
	if (fmod((pro_i), noise->scale1) == 0.0)
		return (noise->col1);
	else
		return (noise->col2);
}
