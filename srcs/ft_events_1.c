/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:06:06 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/09 17:36:35 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_slot(int key, t_ptr *p)
{
	if (key == MLX_KEY_D && PS->curr_object != NULL && PS->object->next != NULL)
	{
		ft_delete_object(&PS->object, &PS->curr_object);
		ft_draw(p);
	}
	if (p->cam_slct && (key == MLX_KEY_X || key == MLX_KEY_Y))
		ft_cam_rotation(key, p);
	if (ft_menu_event(key, p))
		ft_background(p);
	if (RE_DRAW(key))
		ft_draw(p);
}

static void		ft_change_params(int key, t_vector *pos, t_ptr *p)
{
	if (key == MLX_KEY_LEFT && pos)
		pos->v1 -= 0.3 * PS->speed;
	if (key == MLX_KEY_RIGHT && pos)
		pos->v1 += 0.3 * PS->speed;
	if (key == MLX_KEY_UP && pos)
		pos->v2 += 0.3 * PS->speed;
	if (key == MLX_KEY_DOWN && pos)
		pos->v2 -= 0.3 * PS->speed;
	if (key == MLX_KEY_PLUS && pos)
		pos->v3 += 0.3 * PS->speed;
	if (key == MLX_KEY_MINUS && pos)
		pos->v3 -= 0.3 * PS->speed;
}

static void		ft_save_data(int key, t_ptr *p)
{
	if (key == MLX_KEY_I)
		ft_save_img(p);
	if (key == MLX_KEY_V)
		ft_save_video(p);
}

int				ft_deal_key(int key, t_ptr *p)
{
	t_vector	*pos;

	pos = NULL;
	if (key == MLX_KEY_ESC)
		ft_close(p);
	ft_selected_event(key, p);
	ft_cam_light_event(key, p);
	pos = (p->cam_slct) ? &PS->cam.origin : pos;
	pos = (p->light_slct) ? &p->curr_light->pos : pos;
	pos = (PS->curr_object != NULL) ? &PS->curr_object->pos : pos;
	ft_change_params(key, pos, p);
	if (PSC && (ft_strcmp(PS->curr_object->name, "CUBE") == 0
				|| ft_strcmp(PS->curr_object->name, "CYLINDER") == 0))
		ft_pos(PSC);
	if (key == KEY_SPACEBAR && p->inc_dec == 1)
		p->filter = p->filter == GRAY5_FILTER ? 0 : p->filter + 1;
	if (key == KEY_SPACEBAR && p->inc_dec == -1)
		p->filter = p->filter == NONE_FILTER ? GRAY5_FILTER : p->filter - 1;
	PS->cam = ft_init_camera(PS->cam.origin, PS->cam.lookat, PS->cam.fov);
	ft_slot(key, p);
	if (key == MLX_KEY_I || key == MLX_KEY_V)
		ft_save_data(key, p);
	return (key);
}

int				ft_mouse_press(int button, int x, int y, t_ptr *p)
{
	if (button == 1 && COND_SELECT(x, y))
	{
		ft_select_obj(p, x - FRAME, (int)IMG_HEIGHT - (y - MENU_BAR));
		if (PS->curr_object != NULL)
		{
			p->light_slct = 0;
			p->cam_slct = 0;
		}
	}
	if (button == 2)
		PS->curr_object = NULL;
	ft_background(p);
	return (0);
}
