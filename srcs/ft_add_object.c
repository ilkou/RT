/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:48:32 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 17:49:14 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_check_3(char **line, t_object *obj, int *i)
{
	if (!ft_strcmp(*line, C_S) && (obj->hit = HIT_S))
	{
		*i = 1;
		obj->name = ft_strdup("SPHERE");
	}
	else if (!ft_strcmp(*line, C_P) && (obj->hit = HIT_P))
	{
		*i = 1;
		obj->name = ft_strdup("PLANE");
	}
	else if (!ft_strcmp(*line, C_CY) && (obj->hit = HIT_CY))
	{
		*i = 1;
		obj->name = ft_strdup("CYLINDER");
	}
	else if (!ft_strcmp(*line, C_CO) && (obj->hit = HIT_CO))
	{
		*i = 1;
		obj->name = ft_strdup("CONE");
	}
	else if (!ft_strcmp(*line, C_D) && (obj->hit = HIT_D))
	{
		*i = 1;
		obj->name = ft_strdup("DISK");
	}
}

static void		ft_check_2(char **line, t_object *obj, int *i)
{
	if (!ft_strcmp(*line, C_T) && (obj->hit = HIT_T))
	{
		*i = 1;
		obj->name = ft_strdup("TORUS");
	}
	else if (!ft_strcmp(*line, C_PA) && (obj->hit = HIT_PA))
	{
		*i = 1;
		obj->name = ft_strdup("PARABOLOID");
	}
	else if (!ft_strcmp(*line, C_H) && (obj->hit = HIT_H))
	{
		*i = 1;
		obj->name = ft_strdup("HYPERBOLOID");
	}
	else if (!ft_strcmp(*line, C_PC) && (obj->hit = HIT_PC))
	{
		*i = 1;
		obj->name = ft_strdup("PERFORATED CUBE");
	}
	else if (!ft_strcmp(*line, C_TR) && (obj->hit = HIT_TR))
	{
		*i = 1;
		obj->name = ft_strdup("TRIANGLE");
	}
}

static void		ft_check_obj(t_ptr *p, char **line, t_object *obj)
{
	int i;

	i = 0;
	ft_check_3(line, obj, &i);
	ft_check_2(line, obj, &i);
	if (!ft_strcmp(*line, C_CU) && (obj->hit = HIT_CU))
	{
		i = 1;
		obj->name = ft_strdup("CUBE");
	}
	if (!ft_strcmp(*line, C_M) && (obj->hit = HIT_M))
	{
		i = 1;
		obj->name = ft_strdup("MOEBIUS");
	}
	if (i == 0 && FR(*line, 1))
		ft_free_exit("object syntax - undefined object\n", 1, &p);
}

static void		ft_init_object(t_object *obj)
{
	obj->pos = VEC(0, 0, 0);
	obj->col = COL(0, 0, 0);
	obj->size = 1;
	obj->height = -1;
	obj->weight = 0.0;
	obj->rot = VEC(0, 1, 0);
	obj->ka = 0.25;
	obj->kd = 0.75;
	obj->ks = 1.0;
	obj->ke = 30.0;
	obj->kr = 0.0;
	obj->spec = PHONG;
}

void			ft_add_object(t_ptr *p, int fd, char **line, int t)
{
	t_object		*obj;
	t_object		*tmp;

	if (!(obj = (struct s_o *)malloc(sizeof(struct s_o))) && t < 0)
		ft_free_exit("", 1337, &p);
	tmp = p->scene->object;
	ft_check_obj(p, line, obj);
	ft_init_object(obj);
	if (get_next_line(fd, line) > 0 && ft_strcmp(*line, "\t{") && FR(*line, 1))
		ft_free_exit("Object syntax - near to {\n", 1, &p);
	ft_get_object(p, obj, fd, line);
	obj->cont = NULL;
	p->scene->object = obj;
	obj->next = tmp;
}
