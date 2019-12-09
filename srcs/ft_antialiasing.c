/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antialiasing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:28:44 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 17:53:39 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_color		ft_ray_tracer(t_thread *p, double col, double row)
{
	t_color		c;
	t_ray		r;
	t_point		po[2];

	r = (t_ray) {VEC(0, 0, 0), VEC(0, 0, 0)};
	c = COL(0, 0, 0);
	po[0].x = -1;
	while (++po[0].x < PS->anti_a)
	{
		po[0].y = -1;
		while (++po[0].y < PS->anti_a)
		{
			po[1].x = (col + (po[0].x + 0.5) / PS->anti_a) / IMG_WIDTH;
			po[1].y = (row + (po[0].y + 0.5) / PS->anti_a) / IMG_HEIGHT;
			r = ft_get_ray(&PS->cam, po[1].x, po[1].y);
			c = ft_add_c(c, ft_tracer(p, &r, 50));
		}
	}
	c = ft_div_kc(c, PS->anti_a * PS->anti_a);
	ft_set_filter(&c, p->e->filter);
	return (c);
}
