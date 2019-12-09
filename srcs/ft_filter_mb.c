/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_mb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:24:06 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 18:05:58 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_mb_loop(int *d, t_ipoint *loop, t_ipoint *filter, t_color *c)
{
	t_ipoint	img;

	img.x = (int)(loop->x - FILTER_MB_W / 2 + filter->x + IMG_WIDTH)
		% (int)IMG_WIDTH;
	img.y = (int)(loop->y - FILTER_MB_H / 2 + filter->y + IMG_HEIGHT)
		% (int)IMG_HEIGHT;
	c->r += I_TO_R(d[img.y * (int)IMG_WIDTH + img.x])
		* (filter->x == filter->y ? 1 : 0);
	c->g += I_TO_G(d[img.y * (int)IMG_WIDTH + img.x])
		* (filter->x == filter->y ? 1 : 0);
	c->b += I_TO_B(d[img.y * (int)IMG_WIDTH + img.x])
		* (filter->x == filter->y ? 1 : 0);
}

void			ft_filter_mb(int *data)
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
			c = COL(0.0, 0.0, 0.0);
			filter.y = -1;
			while (++filter.y < FILTER_MB_H)
			{
				filter.x = -1;
				while (++filter.x < FILTER_MB_W)
					ft_mb_loop(data, &loop, &filter, &c);
				data[loop.y * (int)IMG_WIDTH + loop.x] =
					RGBTOI(ft_clamp_int((int)(c.r / 9.0), 0, 255),
							ft_clamp_int((int)(c.g / 9.0), 0, 255),
							ft_clamp_int((int)(c.b / 9.0), 0, 255));
			}
		}
	}
}
