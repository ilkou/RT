/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lighting_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:58:10 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 17:23:18 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static double	negative_rand(void)
{
	return (ft_rand48() * (ft_rand48() < ft_rand48() ? -1.0 : 1.0));
}

t_vector		ft_rand_in_sphere(t_vector center, double radius)
{
	t_vector	randxyz;
	t_vector	randvector;
	t_vector	temp;

	randxyz = VEC(negative_rand() * 100.0,
			negative_rand() * 100.0, negative_rand() * 100.0);
	randvector = ft_normalize(ft_sub(randxyz, center));
	temp = ft_pro_k(randvector, radius);
	return (ft_add(center, temp));
}

t_vector		ft_reflect(t_vector v, t_vector n)
{
	return (ft_sub(v, ft_pro_k(ft_pro_k(n, 2), ft_dot(v, n))));
}

void			ft_adjustment(t_color *c)
{
	c->r = ft_clamping(c->r);
	c->g = ft_clamping(c->g);
	c->b = ft_clamping(c->b);
}
