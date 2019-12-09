/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:54:03 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:16:12 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_free_conts(t_object **object)
{
	t_object	*obj;
	t_object	*tmp;

	obj = *object;
	while (obj != NULL)
	{
		tmp = obj->cont;
		if (obj->cont != NULL)
		{
			free(obj->cont->name);
			free(obj->cont);
		}
		obj = tmp;
	}
}

void		ft_free_objects(t_object **object, void *mlx, int end)
{
	t_object	*obj;
	t_object	*tmp;

	obj = *object;
	(void)mlx;
	while (obj != NULL)
	{
		if (obj->cont != NULL)
			ft_free_conts(&obj);
		tmp = obj->next;
		if (end && obj->noi.is_noise == 1 && IS_PERLIN(obj->noi.type))
		{
			free(obj->noi.p.ranvec);
			free(obj->noi.p.perm_x);
			free(obj->noi.p.perm_y);
			free(obj->noi.p.perm_z);
		}
		if (end && obj->txt.is_txt == 1)
			SDL_FreeSurface(obj->txt.surface);
		free(obj->name);
		free(obj);
		obj = tmp;
	}
}

void		ft_free_lights(t_light **light)
{
	t_light		*l;
	t_light		*tmp;

	l = *light;
	while (l != NULL)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

char		*ft_copy_imgdata(int *img, int width, int height)
{
	int		i;
	char	*buffer;
	int		*data;

	if (!(buffer = malloc(4 * width * height)))
		return (NULL);
	data = (int*)buffer;
	i = -1;
	while (++i < width * height)
		data[i] = img[i];
	return (buffer);
}
