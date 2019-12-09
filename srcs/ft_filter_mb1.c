/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_mb1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:24:38 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/20 14:11:19 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_mb1(int *d, t_ipoint *loop, t_ipoint *filter, t_color *c)
{
	t_ipoint	img;

	img.x = (int)(loop->x - FILTER_MB1_W / 2 + filter->x + IMG_WIDTH)
		% (int)IMG_WIDTH;
	img.y = (int)(loop->y - FILTER_MB1_H / 2 + filter->y + IMG_HEIGHT)
		% (int)IMG_HEIGHT;
	c->r += I_TO_R(d[img.y * (int)IMG_WIDTH + img.x])
		* (FILTER_COND(filter->x, filter->y) ? 0 : 1);
	c->g += I_TO_G(d[img.y * (int)IMG_WIDTH + img.x])
		* (FILTER_COND(filter->x, filter->y) ? 0 : 1);
	c->b += I_TO_B(d[img.y * (int)IMG_WIDTH + img.x])
		* (FILTER_COND(filter->x, filter->y) ? 0 : 1);
}

static int		ft_mb1_selected(t_ptr *p, t_ipoint *loop)
{
	t_ray r;

	r = ft_get_ray(&PS->cam, (double)(loop->x + 0.5) / IMG_WIDTH,
			(double)((IMG_HEIGHT - loop->y) + 0.5) / IMG_HEIGHT);
	if (ft_hit(p->scene, r, I(0.0001, DBL_MAX), &PS->record))
	{
		if (p->scene->curr_object != NULL && PS->curr_object == PSRC)
			return (1);
	}
	return (0);
}

static void		ft_fill_data(int *data, t_ipoint *loop, t_color *c)
{
	data[loop->y * (int)IMG_WIDTH + loop->x] =
		RGBTOI(ft_clamp_int((int)(c->r / 13.0), 0, 255),
				ft_clamp_int((int)(c->g / 13.0), 0, 255),
				ft_clamp_int((int)(c->b / 13.0), 0, 255));
}

void			ft_filter_mb1(t_ptr *p, int *data)
{
	t_ipoint	loop;
	t_ipoint	filter;
	t_color		c;

	loop.x = -1;
	while (++loop.x < IMG_WIDTH)
	{
		loop.y = -1;
		while (++loop.y < IMG_HEIGHT)
		{
			if (ft_mb1_selected(p, &loop))
				continue ;
			c = COL(0.0, 0.0, 0.0);
			filter.y = -1;
			while (++filter.y < FILTER_MB1_H)
			{
				filter.x = -1;
				while (++filter.x < FILTER_MB1_W)
					ft_mb1(data, &loop, &filter, &c);
				ft_fill_data(data, &loop, &c);
			}
		}
	}
}
