/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:07:01 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/17 23:50:08 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_sepia_filter(t_color *c)
{
	t_color		v;

	v.r = (c->r * .393) + (c->g * .769) + (c->b * .189);
	v.g = (c->r * .349) + (c->g * .686) + (c->b * .168);
	v.b = (c->r * .272) + (c->g * .534) + (c->b * .131);
	*c = v;
	ft_adjustment(c);
}

void			ft_set_filter(t_color *c, int filter)
{
	double		min;
	double		max;

	min = ft_mind3(c->r, c->g, c->b);
	max = ft_maxd3(c->r, c->g, c->b);
	if (filter == SEPIA_FILTER)
		ft_sepia_filter(c);
	else if (filter == RED_FILTER)
		*c = ft_pro_c(*c, COL(1, 0, 0));
	else if (filter == GREEN_FILTER)
		*c = ft_pro_c(*c, COL(0, 1, 0));
	else if (filter == BLUE_FILTER)
		*c = ft_pro_c(*c, COL(0, 0, 1));
	else if (filter == GRAY1_FILTER)
		*c = COL(c->r, c->r, c->r);
	else if (filter == GRAY2_FILTER)
		*c = COL(c->g, c->g, c->g);
	else if (filter == GRAY3_FILTER)
		*c = COL(c->b, c->b, c->b);
	else if (filter == GRAY4_FILTER)
		*c = COL(min, min, min);
	else if (filter == GRAY5_FILTER)
		*c = COL(max, max, max);
	else if (filter == NEGATIVE_FILTER)
		*c = COL(1.0 - c->r, 1.0 - c->g, 1.0 - c->b);
}
