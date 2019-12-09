/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:53:02 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/16 22:43:23 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ray		ft_ray(t_vector a, t_vector b)
{
	t_ray	r;

	r.origin = a;
	r.dir = b;
	return (r);
}

t_vector	ft_ray_function(t_ray *r, double t)
{
	return (ft_add(r->origin, ft_pro_k(r->dir, t)));
}

double		ffmin(double a, double b)
{
	return (a < b ? a : b);
}

double		ffmax(double a, double b)
{
	return (a > b ? a : b);
}

t_ray		ft_get_ray(t_camera *p, double u, double v)
{
	return (ft_ray(p->origin, ft_normalize(ft_sub(ft_add(p->lower_left_corner,
							ft_add(ft_pro_k(p->horizontal, u),
								ft_pro_k(p->vertical, v))), p->origin))));
}
