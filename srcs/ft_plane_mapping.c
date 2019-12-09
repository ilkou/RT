/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:40 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:16:57 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			ft_plane_mapping(t_hit *rec, t_object *o)
{
	rec->u = ft_dot(ft_div_k(ft_sub(rec->p, o->pos), o->txt.scale * 10.0),
			o->j);
	rec->v = ft_dot(ft_div_k(ft_sub(rec->p, o->pos), o->txt.scale * 10.0),
			o->i);
	rec->u = rec->u - floor(rec->u);
	rec->v = rec->v - floor(rec->v);
}
