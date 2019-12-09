/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voronoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:17:16 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 14:19:54 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static void		ft_voronoi_1(t_cell *c, t_vector value)
{
	t_cell		tmp;
	t_vector	cellposition;
	t_3loop		d;

	d.i = -2;
	while (++d.i <= 1)
	{
		d.j = -2;
		while (++d.j <= 1)
		{
			d.k = -2;
			while (++d.k <= 1)
			{
				tmp.base = c->base;
				tmp.closest = ft_add(c->base, VEC(d.i, d.j, d.k));
				cellposition = ft_add(tmp.closest, ft_rand3dto3d(tmp.closest));
				tmp.toclosest = ft_sub(cellposition, value);
				tmp.mindisttocell = ft_length(tmp.toclosest);
				if (tmp.mindisttocell < c->mindisttocell)
					*c = tmp;
			}
		}
	}
}

static void		ft_set_minedgedistance(t_cell *c, t_cell2 *tmp,\
				float *minedgedistance)
{
	tmp->tocenter = ft_pro_k(ft_add(c->toclosest, tmp->tocell), 0.5);
	tmp->celldifference = ft_normalize(ft_sub(tmp->tocell, c->toclosest));
	tmp->edgedistance = ft_dot(tmp->tocenter, tmp->celldifference);
	*minedgedistance = ffmin(*minedgedistance, tmp->edgedistance);
}

static void		ft_voronoi_2(t_cell *c, float *minedgedistance, t_vector value)
{
	t_cell2	tmp;
	t_3loop	d;

	d.i = -2;
	while (++d.i <= 1)
	{
		d.j = -2;
		while (++d.j <= 1)
		{
			d.k = -2;
			while (++d.k <= 1)
			{
				tmp.cell = ft_add(c->base, VEC(d.i, d.j, d.k));
				tmp.cellposition = ft_add(tmp.cell, ft_rand3dto3d(tmp.cell));
				tmp.tocell = ft_sub(tmp.cellposition, value);
				tmp.diff = ft_vabs(ft_sub(c->closest, tmp.cell));
				if (tmp.diff.v1 + tmp.diff.v2 + tmp.diff.v3 >= 0.1)
					ft_set_minedgedistance(c, &tmp, minedgedistance);
			}
		}
	}
}

static t_vector	ft_voronoi(t_vector value, int voronoi)
{
	t_cell	c;
	float	minedgedistance;
	float	random;

	c.base = ft_vfloor(value);
	c.mindisttocell = 10;
	ft_voronoi_1(&c, value);
	minedgedistance = 10;
	if (voronoi != VORONOI_1)
		ft_voronoi_2(&c, &minedgedistance, value);
	random = ft_rand3dto1d(c.closest, VEC(12.9898, 78.233, 37.719));
	return (VEC(c.mindisttocell, random, minedgedistance));
}

t_color			ft_voronoi_noise(t_vector p, t_color c_border, t_noise *noise)
{
	t_voronoi v;

	v.value = ft_div_k(p, noise->scale1);
	v.noise = ft_voronoi(v.value, noise->type);
	if (noise->type == VORONOI_0)
		return (COL(v.noise.v2 + v.noise.v3, v.noise.v2 + v.noise.v3,
					v.noise.v2 + v.noise.v3));
	else if (noise->type == VORONOI_1)
		return (COL(v.noise.v2, v.noise.v2, v.noise.v2));
	else if (noise->type == VORONOI_2)
		return (COL(v.noise.v3, v.noise.v3, v.noise.v3));
	else if (noise->type == VORONOI_3)
		return (ft_vectocol(v.noise));
	v.cellcolor = ft_rand1dto3d(v.noise.v2);
	if (noise->type == VORONOI_4)
		return (ft_lerp(ft_vectocol(v.cellcolor), c_border, 0.0));
	else if (noise->type == VORONOI_5)
		return (ft_lerp(ft_vectocol(v.cellcolor),
					c_border, ft_step(v.noise.v3, noise->scale2)));
		v.valuechange = ft_length(v.value) * 0.0005;
	v.isborder = 1.0 - ft_smoothstep(noise->scale2 - v.valuechange,
			noise->scale2 + v.valuechange, v.noise.v3);
	return (ft_lerp(ft_vectocol(v.cellcolor), c_border, v.isborder));
}
