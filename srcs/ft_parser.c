/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:27:23 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/21 21:59:06 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_do_rot(t_ptr *p, t_vector *ret, char **each)
{
	double		theta[3];

	theta[0] = ft_atod(each[3]);
	theta[1] = ft_atod(each[4]);
	theta[2] = ft_atod(each[5]);
	if (theta[0] < -180.0 || theta[0] > 180.0 || theta[1] < -180.0
	|| theta[1] > 180.0 || theta[2] < -180.0 || theta[2] > 180.0)
	{
		ft_free_twodim(&each);
		ft_free_exit("wrong rotation angle detected\n", 1, &p);
	}
	ret->v1 = ft_atod(each[0]);
	ret->v2 = ft_atod(each[1]);
	ret->v3 = ft_atod(each[2]);
	*ret = ft_normalize(*ret);
	*ret = theta[0] != 0.0 ? ft_rot_x(*ret, DEG_TO_RAD(theta[0])) : *ret;
	*ret = theta[1] != 0.0 ? ft_rot_y(*ret, DEG_TO_RAD(theta[1])) : *ret;
	*ret = theta[2] != 0.0 ? ft_rot_z(*ret, DEG_TO_RAD(theta[2])) : *ret;
}

t_vector	ft_linetorot(t_ptr *p, char **line, int free_it)
{
	t_vector	ret;
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
	if (ft_twodimlen(each) != 6)
		ft_free_exit("must be sex values for such data\n", 1, &p);
	ft_do_rot(p, &ret, each);
	ft_free_twodim(&each);
	return (ret);
}

t_vector	ft_linetovec(t_ptr *p, char **line, int free_it)
{
	t_vector	ret;
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
	ret.v1 = ft_atod(each[0]);
	ret.v2 = ft_atod(each[1]);
	ret.v3 = ft_atod(each[2]);
	ft_free_twodim(&each);
	return (ret);
}

double		ft_linetod(t_ptr *p, char **line, int free_it)
{
	double		ret;
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
	if (ft_twodimlen(each) != 1)
		ft_free_exit("must be one value for such data\n", 1, &p);
	ret = ft_atod(each[0]);
	ft_free_twodim(&each);
	return (ret);
}

void		ft_linetocoef(t_object *o, t_ptr *p, char **line, int free_it)
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
	if (ft_twodimlen(each) != 5)
		ft_free_exit("must be five values for such data\n", 1, &p);
	o->ka = ft_clamping(ft_atod(each[0]));
	o->kd = ft_clamping(ft_atod(each[1]));
	o->ks = ft_clamping(ft_atod(each[2]));
	o->ke = ft_atod(each[3]);
	o->spec = ft_atod(each[4]) == 0.0 ? BLINN_PHONG : PHONG;
	ft_free_twodim(&each);
}
