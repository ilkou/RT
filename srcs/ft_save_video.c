/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_video.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:22:07 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/12/02 21:14:55 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static char		*img_name(char *str)
{
	int			i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '/')
			return (&str[i + 1]);
		i--;
	}
	return (str);
}

static void		save_img(t_ptr *p, int nbr)
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
	while (++row < IMG_HEIGHT && (col = -1) < 0)
	{
		while (++col < IMG_WIDTH)
		{
			if (col >= 0 && col < IMG_WIDTH && row >= 0 && row < IMG_HEIGHT)
				pixels[row * (int)IMG_WIDTH + col] = SDL_MapRGBA(
						surface->format, I_TO_R(p->data[row
							* (int)IMG_WIDTH + col]),
						I_TO_G(p->data[row * (int)IMG_WIDTH + col]),
						I_TO_B(p->data[row * (int)IMG_WIDTH + col]), 255);
		}
	}
	IMG_SavePNG(surface, ft_mystrjoin(img_name(p->save_img),
				ft_mystrjoin(ft_itoa(nbr + 1), ".png", 0), 1));
	SDL_FreeSurface(surface);
}

void			ft_save_video(t_ptr *p)
{
	int			img_nbr;
	double		angle;

	img_nbr = -1;
	angle = 360.0 / (double)IMG_NBR;
	save_img(p, img_nbr);
	while (++img_nbr < IMG_NBR)
	{
		PS->cam.origin = ft_rotcam_y(PS->cam.origin, DEG_TO_RAD(angle));
		if (PS->light)
			PS->light->pos = ft_rotcam_y(PS->light->pos, DEG_TO_RAD(angle));
		PS->cam = ft_init_camera(PS->cam.origin, PS->cam.lookat, PS->cam.fov);
		ft_begin(p);
		save_img(p, img_nbr);
	}
	ft_putstr("images are computed successfully !\n");
	mlx_put_image_to_window(p->mlx, p->win, p->img, FRAME, MENU_BAR);
}
