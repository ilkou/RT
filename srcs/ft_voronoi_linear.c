/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voronoi_linear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:17:39 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 14:38:43 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
 ** return a or b depends on f
 ** a + f * (b - a)
*/

t_color	ft_lerp(t_color a, t_color b, float f)
{
	return (ft_add_c(a, ft_pro_kc(COL(b.r - a.r, b.g - a.g, b.b - a.b), f)));
}

double	ft_frac(double value)
{
	return (value - floor(value));
}

float	ft_step(float a, float x)
{
	return (x >= a);
}

/*
 ** https://thebookofshaders.com/glossary/?search=smoothstep
*/

float	ft_smoothstep(float a, float b, float x)
{
	float t;

	if (b != a)
		t = ft_clamping((x - a) / (b - a));
	else
		t = ft_clamping(a);
	return (t * t * (3.0 - 2.0 * t));
}
