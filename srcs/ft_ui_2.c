/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:57:55 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 14:56:39 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_check_data(t_ptr *p)
{
	t_object	*tmp;

	PS->cam.origin = VEC(PS->cam.origin.v1 + 0.0001, PS->cam.origin.v2 + 0.0001,
			PS->cam.origin.v3 + 0.0001);
	PS->cam = ft_init_camera(PS->cam.origin, PS->cam.lookat, PS->cam.fov);
	PS->anti_a = PS->anti_a < 1 ? 1 : pow(2, floor(log(PS->anti_a) / log(2)));
	p->filter = p->filter >= 0 && p->filter <= 13 ? p->filter : NONE_FILTER;
	tmp = p->scene->object;
	if (p->scene->cam.fov < 0.0 || p->scene->cam.fov > 180.0)
		ft_free_exit("wrong field of view value\n", 1, &p);
	while (tmp)
	{
		tmp->rotaxis = ROT_Y;
		tmp->txt.is_txt = (tmp->txt.is_txt != 1337) ? 0 : 1;
		tmp->noi.is_noise = (tmp->noi.is_noise != 1337) ? 0 : 1;
		tmp->col = tmp->txt.is_txt || tmp->noi.is_noise ?
			COL(0, 0, 0) : tmp->col;
		if (tmp->txt.is_txt == 0 && tmp->noi.is_noise == 0
				&& (COL_TYPE(tmp->col.r)
				|| COL_TYPE(tmp->col.g) || COL_TYPE(tmp->col.b)))
			ft_free_exit("wrong color / detected\n", 1, &p);
		ft_vects(tmp);
		tmp = tmp->next;
	}
}

void		ft_object_selected(t_ptr *p)
{
	char	*size;
	char	*col;
	char	*pos;
	char	*rot;

	size = PS->curr_object->size == INFINITY ? ft_strdup("INFINITY")
		: ft_dtoa(PS->curr_object->size);
	col = ft_ctoa(PS->curr_object->col);
	pos = ft_vtoa(PS->curr_object->pos);
	rot = ft_vtoa(PS->curr_object->rot);
	MSP(p->mlx, p->win, FRAME + 110, FRAME + 10, COL2, PS->curr_object->name);
	MSP(p->mlx, p->win, FRAME + 110, FRAME + 30, COL2, pos);
	MSP(p->mlx, p->win, FRAME + 110, FRAME + 50, COL2, rot);
	MSP(p->mlx, p->win, FRAME + 110, FRAME + 70, COL2, col);
	MSP(p->mlx, p->win, FRAME + 110, FRAME + 90, COL2, size);
	free(size);
	free(col);
	free(pos);
	free(rot);
}

void		ft_display_properties(t_ptr *p)
{
	char	*cam;
	char	*theta;
	char	*anti_a;
	char	*speed;

	cam = ft_vtoa(PS->cam.origin);
	theta = ft_dtoa(PS->theta);
	anti_a = ft_dtoa(PS->anti_a);
	speed = ft_dtoa(PS->speed);
	MSP(p->mlx, p->win, FRAME + 510, FRAME + 10, COL2, cam);
	MSP(p->mlx, p->win, FRAME + 510, FRAME + 30, COL2, theta);
	MSP(p->mlx, p->win, FRAME + 510, FRAME + 50, COL2, anti_a);
	MSP(p->mlx, p->win, FRAME + 510, FRAME + 70, COL2, speed);
	free(cam);
	free(theta);
	free(anti_a);
	free(speed);
}

void		ft_display_moves(t_ptr *p)
{
	if (p->inc_dec == 1)
	{
		MSP(p->mlx, p->win, FRAME + 710, FRAME + 10, COL2, "Increase/");
		MSP(p->mlx, p->win, FRAME + 800, FRAME + 10, COL1, "Decrease");
	}
	else
	{
		MSP(p->mlx, p->win, FRAME + 710, FRAME + 10, COL1, "Increase/");
		MSP(p->mlx, p->win, FRAME + 800, FRAME + 10, COL2, "Decrease");
	}
	MSP(p->mlx, p->win, FRAME + 640, FRAME + 30, COL1,
			"[X|Y|Z]: Rotation about x/y/z axis");
	MSP(p->mlx, p->win, FRAME + 640, FRAME + 50, COL1, "[<X>|^Yv|-Z+]: Move");
	MSP(p->mlx, p->win, FRAME + 640, FRAME + 70, COL1, "[C]: Camera ");
	(p->cam_slct) ?
		MSP(p->mlx, p->win, FRAME + 760, FRAME + 70, COL2, "Selected") :
		MSP(p->mlx, p->win, FRAME + 760, FRAME + 70, COL1, "Unselected");
	MSP(p->mlx, p->win, FRAME + 640, FRAME + 90, COL1, "[L]: Lights ");
	(p->light_slct) ?
		MSP(p->mlx, p->win, FRAME + 760, FRAME + 90, COL2, "Selected") :
		MSP(p->mlx, p->win, FRAME + 760, FRAME + 90, COL1, "Unselected");
}
