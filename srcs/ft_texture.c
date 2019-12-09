/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 01:47:28 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 15:26:28 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** n'oublie pas de charger l'image en RAM (et non en VRAM), ou alors,
** si c'est en VRAM, d'utiliser SDL_LockSurface.
*/

t_color		ft_get_texture(t_texture *t, double *u, double *v)
{
	int		i;
	int		j;
	Uint8	c[3];

	i = *u * t->surface->w;
	j = (1.0 - *v) * t->surface->h - 0.001;
	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	i = (i > t->surface->w - 1) ? t->surface->w - 1 : i;
	j = (j > t->surface->h - 1) ? t->surface->h - 1 : j;
	SDL_GetRGB(t->data[j * t->surface->w + i], t->surface->format,
			&c[0], &c[1], &c[2]);
	return (COL(c[0] / 255.99, (double)c[1] / 255.99,
				(double)c[2] / 255.99));
}
