/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:38:45 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:15:56 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_light			*ft_copy_lights(t_light *old)
{
	t_light		*new;

	if (!old || !(new = (struct s_l*)malloc(sizeof(struct s_l))))
		return (NULL);
	new->pos = old->pos;
	new->col = old->col;
	new->intensity = old->intensity;
	new->dir = old->dir;
	new->flashlight = old->flashlight;
	new->soft = old->soft;
	new->type = old->type;
	new->next = NULL;
	if (old->next)
		new->next = ft_copy_lights(old->next);
	return (new);
}

void			*ft_copy_conts(t_object *old, t_object *new)
{
	t_object	*tt;

	tt = new;
	while (old)
	{
		if (!(new->cont = (struct s_o *)malloc(sizeof(struct s_o))))
			ft_perror_exit();
		new = ft_set_val(old, new);
		old = old->cont;
		new = new->cont;
	}
	return ((void *)tt);
}

t_object		*ft_copy_objects(t_object *old)
{
	t_object	*new;
	t_object	*old_tt;

	if (!old || !(new = (struct s_o *)malloc(sizeof(struct s_o))))
		return (NULL);
	new->name = ft_strdup(old->name);
	ft_init_copy_obj(new, old);
	new->next = NULL;
	new->cont = NULL;
	old_tt = old;
	old = old->cont;
	if (ft_copy_conts(old, new) == NULL)
		return (NULL);
	old = old_tt;
	if (old->next)
		new->next = ft_copy_objects(old->next);
	return (new);
}

t_scene			*ft_copy_scene(t_scene *old)
{
	t_scene		*scene;

	if (!old || !(scene = (struct s_scene*)malloc(sizeof(struct s_scene))))
		return (NULL);
	scene->light = ft_copy_lights(old->light);
	scene->object = ft_copy_objects(old->object);
	scene->anti_a = old->anti_a;
	scene->amb = old->amb;
	scene->cam = old->cam;
	scene->record = old->record;
	scene->speed = old->speed;
	scene->theta = old->theta;
	scene->curr_object = old->curr_object;
	return (scene);
}

t_ptr			*ft_copy_ptr(t_ptr *old)
{
	t_ptr	*new;

	if (!old || !(new = (struct s_ptr*)malloc(sizeof(struct s_ptr))))
		return (NULL);
	new->win = old->win;
	new->mlx = old->mlx;
	new->img = old->img;
	new->data = old->data;
	new->bgimg = old->bgimg;
	new->bgdata = old->bgdata;
	new->cam_slct = old->cam_slct;
	new->light_slct = old->light_slct;
	new->inc_dec = old->inc_dec;
	new->filter = old->filter;
	new->curr_light = old->curr_light;
	new->do_mb = old->do_mb;
	return (new);
}
