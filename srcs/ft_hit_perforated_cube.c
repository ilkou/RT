/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_perforated_cube.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:03:33 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/05 21:45:26 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void	ft_init_pcube(t_object *o, t_ray *ray, double c[5])
{
	c[4] = pow(ray->dir.v1, 4) + pow(ray->dir.v2, 4) + pow(ray->dir.v3, 4);
	c[3] = 4 * (pow(ray->dir.v1, 3) * ray->origin.v1 + pow(ray->dir.v2, 3)
			* ray->origin.v2 + pow(ray->dir.v3, 3) * ray->origin.v3);
	c[2] = 6 * (pow(ray->dir.v1, 2) * pow(ray->origin.v1, 2) +
			pow(ray->dir.v2, 2) * pow(ray->origin.v2, 2) +
			pow(ray->dir.v3, 2) * pow(ray->origin.v3, 2))
		- 5.0 * ft_dot(ray->dir, ray->dir);
	c[1] = 4.0 * (pow(ray->origin.v1, 3) * ray->dir.v1 + pow(ray->origin.v2, 3)
			* ray->dir.v2 + pow(ray->origin.v3, 3) * ray->dir.v3) - 10.0
		* ft_dot(ray->dir, ray->origin);
	c[0] = pow(ray->origin.v1, 4) + pow(ray->origin.v2, 4) +
		pow(ray->origin.v3, 4) - 5.0 *
		ft_dot(ray->origin, ray->origin) + o->size;
}

int		ft_hit_perforated_cube(t_object *o, t_ray *ray, t_interval t, t_hit *r)
{
	double	c[5];
	double	s[4];
	int		x[3];

	x[0] = -1;
	x[1] = 0;
	ft_init_pcube(o, ray, c);
	if ((x[2] = ft_solve_quartic(c, s)))
	{
		while (++x[0] < x[2])
			if (s[x[0]] > t.t_min && s[x[0]] < t.t_max)
			{
				x[1] = 1;
				t.t_max = s[x[0]];
				r->t = s[x[0]];
				r->p = ft_ray_function(ray, r->t);
				r->n = ft_normalize(VEC(4 * pow(r->p.v1, 3) - 10 * r->p.v1,
							4 * pow(r->p.v2, 3) - 10 * r->p.v2,
							4 * pow(r->p.v3, 3) - 10 * r->p.v3));
			}
		return (x[1] == 1);
	}
	return (0);
}
