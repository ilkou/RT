/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:44:36 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:41:57 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_perror_exit(void)
{
	perror("error ");
	exit(0);
}

void		ft_free_exit(char *display, int err, t_ptr **p)
{
	char	*msg;

	if (err == 1337)
		perror("error ");
	else
	{
		msg = ft_strjoin(err ? "error: " : "", display);
		ft_putstr(msg);
		free(msg);
	}
	if ((*p)->save_img)
		free((*p)->save_img);
	ft_free_objects(&(*p)->scene->object, (*p)->mlx, 1);
	ft_free_lights(&(*p)->scene->light);
	free((*p)->scene);
	free(*p);
	exit(0);
}

int			ft_close(t_ptr *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	ft_free_exit("", 0, &p);
	return (0);
}
