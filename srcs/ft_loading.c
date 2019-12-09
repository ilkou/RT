/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:32:45 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/19 23:06:53 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		*ft_loading(t_load *t)
{
	t->img = mlx_new_image(t->p->mlx, LOAD_WIDTH, LOAD_HEIGHT);
	t->data = (int*)mlx_get_data_addr(t->img, &t->p->bpp, &t->p->size,
			&t->p->endian);
	ft_bzero(t->data, LOAD_WIDTH * LOAD_HEIGHT * 4);
	t->tmp = t->count * LOAD_WIDTH / ((int)IMG_HEIGHT * (int)IMG_WIDTH);
	while (t->inc != NBTHREAD)
	{
		t->tmp2 = t->count * LOAD_WIDTH / ((int)IMG_HEIGHT * (int)IMG_WIDTH);
		if (t->tmp != t->tmp2)
		{
			t->tmp = t->tmp2;
			t->col = -1;
			while (++t->col < t->tmp2 && t->tmp2 < LOAD_WIDTH && (t->row = -1))
				while (++t->row < LOAD_HEIGHT)
					t->data[t->row * (int)LOAD_WIDTH + t->col] = 0x00ff00;
			mlx_put_image_to_window(t->p->mlx, t->p->win, t->img, FRAME,
					MENU_BAR + (int)IMG_HEIGHT - FRAME + LOAD_HEIGHT);
			mlx_do_sync(t->p->mlx);
		}
	}
	mlx_destroy_image(t->p->mlx, t->img);
	pthread_exit(NULL);
}

static void	*ft_playme(t_ptr *p)
{
	int			result;
	int			flags;
	Mix_Music	*music;

	result = 0;
	flags = MIX_INIT_MP3;
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		ft_free_exit("Failed to init SDL\n", 1, &p);
	if (flags != (result = Mix_Init(flags)))
		ft_free_exit("Could not initialize mixer \n", 1, &p);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	music = Mix_LoadMUS("data/two.mp3");
	Mix_PlayMusic(music, 1);
	while (Mix_PlayingMusic())
		;
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	pthread_exit(NULL);
}

void		ft_starting(t_ptr *p, int longg)
{
	pthread_t	mus_thread;
	void		*img;
	int			*data;
	int			width;
	int			height;

	width = longg ? 1000 : 500;
	height = longg ? 500 : 421;
	img = mlx_xpm_file_to_image((void*)p->mlx,
			longg ? "data/two.xpm" : "data/still.xpm", &width, &height);
	if (!img)
		ft_free_exit("file xpm is missing\n", 1, &p);
	data = (int *)mlx_get_data_addr(img, &p->bpp, &p->size, &p->endian);
	mlx_put_image_to_window(p->mlx, p->win,
			img, longg ? FRAME : 250, longg ? MENU_BAR : 220);
	if (longg)
		pthread_create(&mus_thread, NULL, (void*)ft_playme, p);
}
