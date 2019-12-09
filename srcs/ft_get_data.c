/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:30:52 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:34:53 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_add_camera(t_ptr *p, int fd, char **line, int t)
{
	t_camera		cam;

	(t > 0) ? ft_free_exit("wrong camera number\n", 1, &p) : (t++);
	if (ft_strcmp(*line, "\t\"Camera\":") && FR(*line, 1))
		ft_free_exit("Camera syntax\n", 1, &p);
	if (get_next_line(fd, line) > 0 && ft_strcmp(*line, "\t{") && FR(*line, 1))
		ft_free_exit("Camera syntax - near to {\n", 1, &p);
	if (get_next_line(fd, line) > 0 && (ft_strncmp(*line, "\t\t\"lookfrom\": \""
					, 15) || END(line) != '"'))
		ft_free_exit("Camera syntax - lookfrom\n", 1, &p);
	cam.origin = ft_linetovec(p, line, 1);
	if (get_next_line(fd, line) > 0 && (ft_strncmp(*line, "\t\t\"lookat\": \""
					, 13) || END(line) != '"'))
		ft_free_exit("Camera syntax - lookat\n", 1, &p);
	cam.lookat = ft_linetovec(p, line, 1);
	if (get_next_line(fd, line) > 0 && (ft_strncmp(*line, "\t\t\"fov\": \""
					, 10) || END(line) != '"'))
		ft_free_exit("Camera syntax - fov\n", 1, &p);
	cam.fov = ft_linetod(p, line, 1);
	if (get_next_line(fd, line) > 0 && ft_strcmp(*line, "\t}") && FR(*line, 1))
		ft_free_exit("Camera syntax - near to }\n", 1, &p);
	p->scene->cam = ft_init_camera(cam.origin, cam.lookat, cam.fov);
}

void		ft_obj_col(t_ptr *p, t_object *obj, char **line)
{
	if (!ft_strncmp(*line, "\t\t\"color\": \"", 12))
		obj->col = ft_linetocol(p, line, 1);
	else if (!ft_strncmp(*line, "\t\t\"texture\": \"", 14))
		ft_linetotxt(&obj->txt, p, line, 1);
	else
		ft_linetonoise(&obj->noi, p, line, 1);
}

void		ft_get_object(t_ptr *p, t_object *obj, int fd, char **l)
{
	while (get_next_line(fd, l) > 0)
	{
		if (!ft_strncmp(*l, "\t\t\"position\": \"", 15) && END(l) == '"')
			obj->pos = ft_linetovec(p, l, 1);
		else if (!ft_strncmp(*l, "\t\t\"rotation\": \""
					, 15) && END(l) == '"')
			obj->rot = ft_normalize(ft_linetorot(p, l, 1));
		else if (!IS_THIRD(*l) && END(l) == '"')
			obj->pos = ft_add(obj->pos, ft_linetovec(p, l, 1));
		else if (!IS_FORTH(*l) && END(l) == '"')
			ft_obj_col(p, obj, l);
		else if (!ft_strncmp(*l, "\t\t\"size\": \"", 11) && END(l) == '"')
			ft_linetosize(obj, p, l, 1);
		else if (!ft_strncmp(*l, "\t\t\"refl\": \"", 10) && END(l) == '"')
			obj->kr = ft_clamping(ft_linetod(p, l, 1));
		else if (!ft_strncmp(*l, "\t\t\"coef\": \"", 10) && END(l) == '"')
			ft_linetocoef(obj, p, l, 1);
		else if (!ft_strcmp(*l, "\t}"))
			break ;
		else
			ft_free_exit(ft_mystrjoin("Object syntax: \n", *l, 1), 1, &p);
	}
}

static void	ft_data_error(int i, int j, t_ptr *p)
{
	if (i == 0 || j == 0)
		ft_free_exit("data missing - minimum \"1camera,1object\"\n", 1, &p);
}

int			ft_get_data(t_ptr *p, int fd, int nbr0, int nbr1)
{
	char			*line;
	t_light			*light[2];

	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strncmp(line, "\t\"Camera\":", 10))
			ft_add_camera(p, fd, &line, nbr0++);
		else if (!ft_strncmp(line, "\t\"Object\": ", 11))
			ft_add_object(p, fd, &line, nbr1++);
		else if (!ft_strncmp(line, "\t\"Light\":", 9))
			ft_add_light(light, p, fd, &line);
		else if (!ft_strncmp(line, "\t\"Anti-al\":", 11))
			p->scene->anti_a = ft_linetod(p, &line, 0);
		else if (!ft_strncmp(line, "\t\"Ambient\":", 11))
			p->scene->amb = ft_clamping(ft_linetod(p, &line, 0));
		else if (!ft_strncmp(line, "\t\"Filter\":", 10))
			p->filter = (int)ft_linetod(p, &line, 0);
		else if (!ft_strncmp(line, "]", 1))
			break ;
		else
			ft_free_exit("unexpected data\n", 1, &p);
		free(line);
	}
	ft_data_error(nbr0, nbr1, p);
	return (nbr1);
}
