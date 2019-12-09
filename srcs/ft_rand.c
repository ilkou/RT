/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:23:32 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 18:46:39 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

float		ft_rand1dto1d(float value, float mutator)
{
	return (ft_frac(sin(value + mutator) * 143758.5453));
}

t_vector	ft_rand1dto3d(float value)
{
	return (VEC(
				ft_rand1dto1d(value, 3.9812),
				ft_rand1dto1d(value, 7.1536),
				ft_rand1dto1d(value, 5.7241)));
}

float		ft_rand3dto1d(t_vector value, t_vector dot_dir)
{
	t_vector	small_value;
	float		random;

	small_value = VEC(cos(value.v1), cos(value.v2), cos(value.v3));
	random = ft_dot(small_value, dot_dir);
	random = ft_frac(sin(random) * 143758.5453);
	return (random);
}

t_vector	ft_rand3dto3d(t_vector value)
{
	return (VEC(
				ft_rand3dto1d(value, VEC(12.989, 78.233, 37.719)),
				ft_rand3dto1d(value, VEC(39.346, 11.135, 83.155)),
				ft_rand3dto1d(value, VEC(73.156, 52.235, 09.151))));
}
