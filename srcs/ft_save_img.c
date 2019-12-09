/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:40:49 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/18 18:37:59 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

static char	*ft_img_name(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '/')
			return (&str[i + 1]);
		i--;
	}
	return (str);
}

void		ft_save_img(t_ptr *p)
{
	SDL_Surface	*surface;
	Uint32		*pixels;
	int			col;
	int			row;

	surface = SDL_CreateRGBSurfaceWithFormat(0, IMG_WIDTH, IMG_HEIGHT
			, 32, SDL_PIXELFORMAT_RGBA8888);
	pixels = surface->pixels;
	SDL_LockSurface(surface);
	row = -1;
	while (++row < IMG_HEIGHT)
	{
		col = -1;
		while (++col < IMG_WIDTH)
		{
			if (col >= 0 && col < IMG_WIDTH && row >= 0 && row < IMG_HEIGHT)
				pixels[row * (int)IMG_WIDTH + col] = SDL_MapRGBA(
				surface->format, I_TO_R(p->data[row * (int)IMG_WIDTH + col]),
				I_TO_G(p->data[row * (int)IMG_WIDTH + col]),
				I_TO_B(p->data[row * (int)IMG_WIDTH + col]), 255);
		}
	}
	IMG_SavePNG(surface, ft_strjoin(ft_img_name(p->save_img), ".png"));
	SDL_FreeSurface(surface);
}
