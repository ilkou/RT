/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:53:05 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/11/22 18:06:55 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		ft_color(int iter, t_noise *noise)
{
	if (iter == 100)
		return (noise->col2);
	if (iter == 0)
		return (noise->col1);
	return (ft_pro_kc(noise->col1, (double)iter / 10.0));
}

t_com		ft_specific_julia(int choix)
{
	if (choix == FRACTAL_0)
		return ((t_com) {0.5, 0.3});
	else if (choix == FRACTAL_1)
		return ((t_com) {0.01, 0.285});
	else if (choix == FRACTAL_2)
		return ((t_com) {0.0099534, -1.417022285618});
	else if (choix == FRACTAL_3)
		return ((t_com) {0.9754633, -0.038088});
	else if (choix == FRACTAL_4)
		return ((t_com) {0.6, -0.4});
	else if (choix == FRACTAL_5)
		return ((t_com) {0.0, -1.476});
	else if (choix == FRACTAL_6)
		return ((t_com) {0.156, -0.8});
	else
		return ((t_com) {0.145, -0.75});
}

t_color		ft_julia(double col, double row, t_noise *noise)
{
	t_com		z;
	t_com		c;
	int			iter;
	double		tmp;

	z.re = col;
	z.im = row;
	c = ft_specific_julia(noise->type);
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < 100)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_color(iter, noise));
}

t_color		ft_get_fractal(t_object *o, t_hit *rec, t_noise *noise)
{
	t_vector	d;
	double		w1;
	double		w2;

	d = ft_sub(o->pos, rec->p);
	if (o->hit == ft_hit_cone)
		d = ft_add(d, ft_pro_k(o->k, noise->scale1));
	if (ft_strcmp(o->name, "SPHERE") == 0)
	{
		w1 = ft_dot(d, o->j) / noise->scale2;
		w2 = ft_dot(d, o->i) / noise->scale2;
	}
	else
	{
		w1 = ft_dot(d, rec->surface == IS_PLANE ?
				rec->i : o->i) / noise->scale2;
		w2 = ft_dot(d, rec->surface == IS_PLANE ?
				rec->j : o->k) / noise->scale1;
	}
	return (ft_julia(w1, w2, noise));
}
