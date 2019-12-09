/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:37:07 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:34:21 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_create_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, IMG_WIDTH, IMG_HEIGHT);
	p->data = (int*)mlx_get_data_addr(p->img, &p->bpp, &p->size, &p->endian);
}

int		ft_parser(t_ptr *p, char *chemin)
{
	int		fd;
	char	*buf;

	buf = NULL;
	if ((fd = open(chemin, O_RDONLY)) == -1)
		ft_free_exit(ft_strjoin(chemin, " : No such file\n"), 1, &p);
	if (read(fd, buf, 0) < 0)
		ft_free_exit(ft_strjoin(chemin, " : must be a file\n"), 1, &p);
	p->save_img = ft_strdup(chemin);
	fd = open(chemin, O_RDONLY);
	get_next_line(fd, &buf);
	if (ft_strcmp(buf, "[") != 0 && FR(buf, 1))
		ft_free_exit("brackets\n", 1, &p);
	free(buf);
	fd = ft_get_data(p, fd, 0, 0);
	ft_check_data(p);
	return (fd);
}

int		main(int argc, char **argv)
{
	t_ptr	*p;
	int		nbr_obj;

	if (!(p = (struct s_ptr*)malloc(sizeof(struct s_ptr))))
		ft_perror_exit();
	p->scene = ft_init_scene();
	ft_init(p);
	p->mlx = mlx_init();
	nbr_obj = 0;
	if (argc == 2)
		nbr_obj = ft_parser(p, argv[1]);
	else
		ft_free_exit("usage: ./rt scene_file\ncheck ./scenes\n", 0, &p);
	p->win = mlx_new_window(p->mlx, WIN_WIDTH, WIN_HEIGHT, "rt");
	ft_create_image(p);
	ft_starting(p, (nbr_obj >= 15 || p->scene->anti_a >= 8) ? 1 : 0);
	ft_background(p);
	ft_draw(p);
	mlx_hook(p->win, 17, (1L << 17), ft_close, p);
	mlx_hook(p->win, 2, (1L << 0), ft_deal_key, p);
	mlx_hook(p->win, 4, 0, ft_mouse_press, p);
	mlx_loop(p->mlx);
	return (0);
}
