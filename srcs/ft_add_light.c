/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:33:56 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/21 22:00:07 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static	t_light	*ft_init_light(t_ptr *p, int fd, char **line, t_light **linked)
{
	t_light *l;

	if (!(l = (struct s_l *)malloc(sizeof(struct s_l))))
		ft_free_exit("", 1337, &p);
	*linked = p->scene->light;
	if (ft_strcmp(*line, "\t\"Light\":") == 0)
		l->type = P_LIGHT;
	else if (ft_strcmp(*line, "\t\"Light\": DIRECTIONAL") == 0)
		l->type = D_LIGHT;
	else if (FR(*line, 1))
		ft_free_exit("Light syntax\n", 1, &p);
	if (get_next_line(fd, line) > 0 && ft_strcmp(*line, "\t{") && FR(*line, 1))
		ft_free_exit("Light syntax - near to {\n", 1, &p);
	l->pos = VEC(50.00001, 50.00001, 50.00001);
	l->col = COL(1, 1, 1);
	l->flashlight = 180.0;
	l->dir = VEC(0, -1, 0);
	l->intensity = 0.02;
	l->soft = (t_ipoint){1, 0};
	return (l);
}

void			ft_add_light(t_light *light[2], t_ptr *p, int fd, char **line)
{
	light[0] = ft_init_light(p, fd, line, &light[1]);
	while (get_next_line(fd, line) > 0)
	{
		if (ft_strncmp(*line, "\t\t\"position\": \"", 15) == 0)
			light[0]->pos = ft_add(ft_linetovec(p, line, 1),
					VEC(0.00001, 0.00001, 0.00001));
		else if (ft_strncmp(*line, "\t\t\"direction\": \"", 16) == 0)
			light[0]->dir = ft_linetovec(p, line, 1);
		else if (ft_strncmp(*line, "\t\t\"color\": \"", 12) == 0)
			light[0]->col = ft_linetocol(p, line, 1);
		else if (ft_strncmp(*line, "\t\t\"intensity\": \"", 16) == 0)
			light[0]->intensity = ft_clamping(ft_linetod(p, line, 1));
		else if (ft_strncmp(*line, "\t\t\"soft\": \"", 11) == 0)
			light[0]->soft = ft_linetosoft(p, line, 1);
		else if (ft_strncmp(*line, "\t\t\"flashlight\": \"", 17) == 0)
			light[0]->flashlight = ft_linetod(p, line, 1);
		else if (ft_strncmp(*line, "\t}", 1) == 0)
			break ;
		else
			ft_free_exit("Light syntax\n", 1, &p);
	}
	p->scene->light = light[0];
	light[0]->next = light[1];
}
