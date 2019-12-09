/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:24:32 by nhamid            #+#    #+#             */
/*   Updated: 2019/11/21 17:11:10 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_object	*ft_set_val(t_object *old, t_object *new)
{
	new->cont->pos = old->pos;
	new->cont->txt = old->txt;
	new->cont->noi = old->noi;
	new->cont->rotaxis = old->rotaxis;
	new->cont->col = old->col;
	new->cont->hit = old->hit;
	new->cont->size = old->size;
	new->cont->weight = old->weight;
	new->cont->height = old->height;
	new->cont->rot = old->rot;
	new->cont->i = old->i;
	new->cont->j = old->j;
	new->cont->k = old->k;
	new->cont->ex_rot = old->ex_rot;
	new->cont->name = ft_strdup(old->name);
	new->cont->next = NULL;
	new->cont->cont = NULL;
	return (new);
}

void		ft_init_copy_obj(t_object *new, t_object *old)
{
	new->pos = old->pos;
	new->txt = old->txt;
	new->noi = old->noi;
	new->rotaxis = old->rotaxis;
	new->col = old->col;
	new->hit = old->hit;
	new->size = old->size;
	new->height = old->height;
	new->weight = old->weight;
	new->rot = old->rot;
	new->i = old->i;
	new->j = old->j;
	new->k = old->k;
	new->ex_rot = old->ex_rot;
	new->ka = old->ka;
	new->kd = old->kd;
	new->ks = old->ks;
	new->ke = old->ke;
	new->kr = old->kr;
	new->spec = old->spec;
}
