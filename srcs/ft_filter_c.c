/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:25:40 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:35:36 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_3loop	select_kth_val(t_3loop p, int e, int s)
{
	p.k = (s + e) / 2;
	p.j = s;
	p.i = s - 1;
	return (p);
}

static int		select_kth(int *data, int s, int e, int k)
{
	t_3loop p;

	p.i = s;
	if (e - s <= 5 && (p.i = s))
	{
		while (++p.i < e)
		{
			p.j = p.i + 1;
			while (--p.j > 0 && data[p.j - 1] > data[p.j])
				ft_swap_i(&data[p.j], &data[p.j - 1]);
		}
		return (s + k);
	}
	p = select_kth_val(p, e, s);
	ft_swap_i(&data[p.k], &data[e - 1]);
	while (++p.i + 1 < e)
		if (data[p.i] < data[e - 1])
			ft_swap_i(&data[p.i], &data[p.j++]);
	ft_swap_i(&data[p.j], &data[e - 1]);
	if (k == p.j - s)
		return (s + k);
	else if (k < p.j - s)
		return (select_kth(data, s, p.j, k));
	else
		return (select_kth(data, p.j + 1, e, k - p.j + s - 1));
}

static void		ft_fill_data(int *data, t_ipoint *loop, int **col)
{
	int		indice;
	int		c1;
	int		c2;
	int		c3;

	indice = loop->y * (int)IMG_WIDTH + loop->x;
	c1 = ft_clamp_int(col[1][select_kth(col[1], 0,
				FILTERSIZE, FILTERSIZE / 2)], 0, 255);
	c2 = ft_clamp_int(col[2][select_kth(col[2], 0,
				FILTERSIZE, FILTERSIZE / 2)], 0, 255);
	c3 = ft_clamp_int(col[3][select_kth(col[3], 0,
				FILTERSIZE, FILTERSIZE / 2)], 0, 255);
	data[indice] = RGBTOI(c1, c2, c3);
}

static void		ft_filter_loop(int **col, int *data, t_ipoint *loop, int n)
{
	t_ipoint	filter;
	t_ipoint	img;

	filter.y = -1;
	while (++filter.y < FILTER_C_H)
	{
		filter.x = -1;
		while (++filter.x < FILTER_C_W)
		{
			img.x = (int)(loop->x - FILTER_C_W / 2 + filter.x + IMG_WIDTH)
				% (int)IMG_WIDTH;
			img.y = (int)(loop->y - FILTER_C_H / 2 + filter.y + IMG_HEIGHT)
				% (int)IMG_HEIGHT;
			col[1][n] = I_TO_R(col[0][img.y * (int)IMG_WIDTH + img.x]);
			col[2][n] = I_TO_G(col[0][img.y * (int)IMG_WIDTH + img.x]);
			col[3][n] = I_TO_B(col[0][img.y * (int)IMG_WIDTH + img.x]);
			n++;
		}
		ft_fill_data(data, loop, col);
	}
}

void			ft_filter_cartoon(int *data)
{
	t_ipoint	loop;
	t_color		c;
	int			*col[4];
	int			n;

	if (!(col[0] = (int*)ft_copy_imgdata(data, IMG_WIDTH, IMG_HEIGHT))
			|| !(col[1] = (int*)ft_memalloc(4 * IMG_HEIGHT * IMG_WIDTH))
			|| !(col[2] = (int*)ft_memalloc(4 * IMG_HEIGHT * IMG_WIDTH))
			|| !(col[3] = (int*)ft_memalloc(4 * IMG_HEIGHT * IMG_WIDTH)))
		ft_perror_exit();
	loop.x = -1;
	while (++loop.x < IMG_WIDTH)
	{
		loop.y = -1;
		while (++loop.y < IMG_HEIGHT && (n = 0) > -1)
		{
			ft_filter_loop(col, data, &loop, n);
			c = COL(0.0, 0.0, 0.0);
		}
	}
	free(col[0]);
	free(col[1]);
	free(col[2]);
	free(col[3]);
}
