/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:42:09 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/17 20:15:30 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_cam_rotation(int key, t_ptr *p)
{
	if (key == MLX_KEY_X)
		PS->cam.origin = ft_rotcam_x(PS->cam.origin, p->inc_dec
				* DEG_TO_RAD(PS->theta));
	if (key == MLX_KEY_Y)
		PS->cam.origin = ft_rotcam_y(PS->cam.origin, p->inc_dec
				* DEG_TO_RAD(PS->theta));
	PS->cam = ft_init_camera(PS->cam.origin, PS->cam.lookat, PS->cam.fov);
}

void		ft_cam_light_event(int key, t_ptr *p)
{
	if (key == MLX_KEY_C)
	{
		p->cam_slct = p->cam_slct == 0 ? 1 : 0;
		p->light_slct = p->cam_slct == 1 ? 0 : p->light_slct;
		PS->curr_object = NULL;
	}
	if (key == MLX_KEY_L && PS->light)
	{
		if (p->light_slct == 0)
		{
			p->curr_light = PS->light;
			p->light_slct = 1;
		}
		else if (p->curr_light->next != NULL)
			p->curr_light = p->curr_light->next;
		else
		{
			p->curr_light = NULL;
			p->light_slct = 0;
		}
		p->cam_slct = p->light_slct == 1 ? 0 : p->cam_slct;
		PS->curr_object = NULL;
	}
}
