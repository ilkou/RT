/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:09:48 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/21 17:02:26 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		ft_linetocol(t_ptr *p, char **line, int free_it)
{
	t_color		ret;
	char		**each;
	char		*str;

	str = *line;
	while (*str && *str != ':')
		str++;
	while (*str && *str != '"')
		str++;
	str++;
	str = ft_strsub(str, 0, ft_strlen(str) - 1);
	each = ft_strsplit(str, ' ');
	free(str);
	if (free_it)
		free(*line);
	if (ft_twodimlen(each) != 3)
		ft_free_exit("must be three values for such data\n", 1, &p);
	ret.r = ft_atod(each[0]);
	ret.g = ft_atod(each[1]);
	ret.b = ft_atod(each[2]);
	ft_free_twodim(&each);
	return (ret);
}

void		ft_linetotxt(t_texture *txt, t_ptr *p, char **line, int free_it)
{
	char		**each;
	char		*str;

	str = *line;
	while (*str && *str != ':')
		str++;
	while (*str && *str != '"')
		str++;
	str++;
	str = ft_strsub(str, 0, ft_strlen(str) - 1);
	each = ft_strsplit(str, ' ');
	free(str);
	if (free_it)
		free(*line);
	if (ft_twodimlen(each) != 2)
		ft_free_exit("must be two values for such data\n", 1, &p);
	txt->is_txt = 1337;
	txt->surface = IMG_Load(each[0]);
	if (!txt->surface)
		ft_free_exit(each[0], 1, &p);
	txt->data = txt->surface->pixels;
	txt->scale = ft_atod(each[1]);
	ft_free_twodim(&each);
}

void		ft_linetonoise(t_noise *noi, t_ptr *p, char **line, int free_it)
{
	char		**each;
	char		*str;

	str = *line;
	while (*str && *str != ':')
		str++;
	while (*str && *str != '"')
		str++;
	str++;
	str = ft_strsub(str, 0, ft_strlen(str) - 1);
	each = ft_strsplit(str, ' ');
	free(str);
	if (free_it)
		free(*line);
	if (ft_twodimlen(each) != 9)
		ft_free_exit("must be nine values for such data\n", 1, &p);
	noi->is_noise = 1337;
	noi->type = ft_atoi(each[0]);
	noi->scale1 = ft_atod(each[1]);
	noi->scale2 = ft_atod(each[2]);
	noi->col1 = COL(ft_atod(each[3]), ft_atod(each[4]), ft_atod(each[5]));
	noi->col2 = COL(ft_atod(each[6]), ft_atod(each[7]), ft_atod(each[8]));
	if (IS_PERLIN(noi->type))
		ft_perlin_init(&noi->p);
	ft_free_twodim(&each);
}

void		ft_linetosize(t_object *o, t_ptr *p, char **line, int free_it)
{
	char		**each;
	char		*str;

	str = *line;
	while (*str && *str != ':')
		str++;
	while (*str && *str != '"')
		str++;
	str++;
	str = ft_strsub(str, 0, ft_strlen(str) - 1);
	each = ft_strsplit(str, ' ');
	free(str);
	if (free_it)
		free(*line);
	if (ft_twodimlen(each) != 3)
		ft_free_exit("must be three values for such data\n", 1, &p);
	o->size = ft_atod(each[0]);
	o->height = ft_atod(each[1]);
	o->weight = ft_atod(each[2]);
	ft_free_twodim(&each);
}

t_ipoint	ft_linetosoft(t_ptr *p, char **line, int free_it)
{
	t_ipoint	size;
	char		**each;
	char		*str;

	str = *line;
	while (*str && *str != ':')
		str++;
	while (*str && *str != '"')
		str++;
	str++;
	str = ft_strsub(str, 0, ft_strlen(str) - 1);
	each = ft_strsplit(str, ' ');
	free(str);
	if (free_it)
		free(*line);
	if (ft_twodimlen(each) != 2)
		ft_free_exit("must be two values for such data\n", 1, &p);
	size.x = ft_atoi(each[0]);
	size.y = ft_atoi(each[1]);
	size.x = size.x > 1 ? size.x : 1;
	size.y = size.y > 0 ? size.y : 0;
	ft_free_twodim(&each);
	return (size);
}
