/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:31:14 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:19:21 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static t_color		ft_get_voronoi(t_object *o, t_hit *rec, t_noise *noise)
{
	t_vector	diff;

	diff = ft_sub(rec->p, o->pos);
	diff = VEC(ft_dot(diff, o->i), ft_dot(diff, o->j), ft_dot(diff, o->k));
	return (ft_voronoi_noise(diff, noise->col1, noise));
}

static t_color		ft_get_perlin(t_object *o, t_hit *rec, t_noise *noise)
{
	t_vector	diff;
	double		mult;
	int			type;

	diff = ft_sub(rec->p, o->pos);
	diff = VEC(ft_dot(diff, o->i), ft_dot(diff, o->j), ft_dot(diff, o->k));
	type = noise->type;
	mult = 0.0;
	if (type == PERLIN_0)
		mult = 0.5 * (1 + sin(noise->scale2 * diff.v3 + 10
					* ft_perlin_noise(&noise->p, diff, noise->scale1)));
	else if (type == PERLIN_1)
		mult = 0.5 * (1 + sin(noise->scale2 * diff.v2 + 5
					* ft_perlin_noise(&noise->p, diff, noise->scale1)));
	else if (type == PERLIN_2)
		mult = 0.5 * (1 + ft_perlin_noise(&noise->p, diff, noise->scale1));
	else
		mult = ft_perlin_noise(&noise->p, diff, noise->scale1);
	return (ft_pro_kc(noise->col1, mult));
}

t_color				ft_get_noise(t_object *o, t_hit *rec, t_noise *noise)
{
	int			type;

	type = noise->type;
	if (type >= VORONOI_0 && type <= VORONOI_6)
		return (ft_get_voronoi(o, rec, noise));
	else if (type >= PERLIN_0 && type <= PERLIN_3)
		return (ft_get_perlin(o, rec, noise));
	else if (type == CHECKER_BOARD)
		return (ft_get_checkerboard(o, rec, noise));
	else if (type >= FRACTAL_0 && type <= FRACTAL_7)
		return (ft_get_fractal(o, rec, noise));
	else if (type == MAMAMIYA)
		return (ft_get_mamamiya(o, rec, noise));
	else if (type == CERCLES)
		return (ft_get_cercles(o, rec, noise));
	return (COL(1, 1, 1));
}
