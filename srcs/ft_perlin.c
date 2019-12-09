/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:27:47 by oouklich          #+#    #+#             */
/*   Updated: 2019/10/04 01:10:02 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

float	ft_acc(t_vector c[2][2][2], t_vector v, float acc)
{
	t_3loop			d;
	t_vector		weight;
	t_vector		noise;

	noise = VEC(v.v1 * v.v1 * (3 - 2 * v.v1), v.v2 * v.v2 * (3 - 2 * v.v2),
			v.v3 * v.v3 * (3 - 2 * v.v3));
	d = (t_3loop){-1, -1, -1};
	while (++d.i < 2)
	{
		d.j = -1;
		while (++d.j < 2)
		{
			d.k = -1;
			while (++d.k < 2)
			{
				weight = VEC(v.v1 - d.i, v.v2 - d.j, v.v3 - d.k);
				acc += (d.i * noise.v1 + (1 - d.i) * (1 - noise.v1)) *
					(d.j * noise.v2 + (1 - d.j) * (1 - noise.v2)) *
					(d.k * noise.v3 + (1 - d.k) * (1 - noise.v3)) *
					ft_dot(c[d.i][d.j][d.k], weight);
			}
		}
	}
	return (acc);
}

float	ft_noise(t_perlin *p, t_vector v)
{
	t_vector		c[2][2][2];
	t_vector		acc;
	t_3loop			d;

	d = (t_3loop){-1, -1, -1};
	while (++d.i < 2)
	{
		d.j = -1;
		while (++d.j < 2)
		{
			d.k = -1;
			while (++d.k < 2)
				c[d.i][d.j][d.k] = p->ranvec[p->perm_x[(IFLR(v.v1) + d.i) & 255]
					^ p->perm_y[(IFLR(v.v2) + d.j) & 255]
					^ p->perm_z[(IFLR(v.v3) + d.k) & 255]];
		}
	}
	acc = VEC(v.v1 - floor(v.v1), v.v2 - floor(v.v2), v.v3 - floor(v.v3));
	return (ft_acc(c, acc, 0.0));
}

float	ft_perlin_noise(t_perlin *p, t_vector v, int depth)
{
	float			acc;
	float			weight;
	int				i;

	acc = 0.0;
	weight = 1.0;
	i = -1;
	while (++i < depth)
	{
		acc += weight * ft_noise(p, v);
		weight *= 0.5;
		v = ft_pro_k(v, 2);
	}
	return (fabs(acc));
}
