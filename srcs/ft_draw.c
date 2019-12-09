/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:04:46 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:40:32 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_color		ft_tracer(t_thread *p, t_ray *r, int d)
{
	t_color		color;
	t_ray		ref;
	double		kr;

	color = COL(0.0, 0.0, 0.0);
	if (ft_hit(p->scene, *r, I(0.0001, DBL_MAX), &PS->record))
	{
		if (PSRC->txt.is_txt == 1 && (GOT_TXT(PSRC->hit)
					|| PSRC->hit == HIT_T || PSRC->hit == HIT_D))
			PS->record.col = ft_get_texture(&PSRC->txt, &PS->record.u,
					&PS->record.v);
		else if (PSRC->noi.is_noise == 1)
			PS->record.col = ft_get_noise(PSRC, &PS->record, &PSRC->noi);
		else
			PS->record.col = PSRC->col;
		ft_lighting(PS, PS->light, &color);
		if (d > 1 && PSRC->kr > 0.0 && (kr = PSRC->kr) > 0.0)
		{
			ref = (t_ray) {PS->record.p, ft_reflect(r->dir, PS->record.n)};
			color = ft_add_c(color, ft_pro_kc(ft_tracer(p
							, &ref, d - 1), kr));
		}
	}
	ft_adjustment(&color);
	return (color);
}

void		*ft_calcul(t_thread *p)
{
	t_color		c;
	int			color;
	int			col;
	int			row;

	row = IMG_HEIGHT + 1;
	while (--row >= 0)
	{
		col = (int)(p->i * IMG_WIDTH / NBTHREAD) - 1;
		while (++col < (int)((p->i + 1) * IMG_WIDTH / NBTHREAD))
		{
			PS->col = row;
			PS->row = col;
			c = ft_ray_tracer(p, col, row);
			color = RGBTOI(RGB(c.r), RGB(c.g), RGB(c.b));
			ft_mlx_putpixel(p->e, col, IMG_HEIGHT - row, color);
			*(p->count) += 1;
		}
	}
	ft_free_objects(&p->scene->object, p->e->mlx, 0);
	ft_free_lights(&p->scene->light);
	free(p->scene);
	free(p->e);
	*(p->inc) += 1;
	pthread_exit(NULL);
}

void		ft_begin(t_ptr *p)
{
	pthread_t	thread[NBTHREAD + 1];
	t_thread	div[NBTHREAD];
	t_load		t;
	int			i;

	i = -1;
	t.inc = 0;
	t.count = 0;
	t.p = p;
	while (++i < NBTHREAD)
	{
		div[i].e = ft_copy_ptr(p);
		div[i].i = i;
		div[i].inc = &t.inc;
		div[i].count = &t.count;
		div[i].scene = ft_copy_scene(p->scene);
		div[i].e->scene = div[i].scene;
		pthread_create(&thread[i], NULL, (void*)ft_calcul, &div[i]);
	}
	pthread_create(&thread[NBTHREAD], NULL, (void*)ft_loading, &t);
	while (--i >= 0)
		pthread_join(thread[i], NULL);
	pthread_join(thread[NBTHREAD], NULL);
}

int			ft_draw(t_ptr *p)
{
	ft_bzero(p->data, IMG_WIDTH * IMG_HEIGHT * 4);
	ft_background(p);
	ft_begin(p);
	if (p->filter == MOTION_BLUR_FILTER)
		ft_filter_mb(p->data);
	else if (p->filter == MOTION_BLUR2_FILTER)
		ft_filter_mb1(p, p->data);
	else if (p->filter == CARTOON_FILTER)
		ft_filter_cartoon(p->data);
	mlx_put_image_to_window(p->mlx, p->win, p->img, FRAME, MENU_BAR);
	return (1);
}
