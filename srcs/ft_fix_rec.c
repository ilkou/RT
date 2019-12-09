/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:52:09 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 17:21:09 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int		ft_fix_rec(t_hit *old, t_hit *new)
{
	old->p = new->p;
	old->t = new->t;
	old->n = new->n;
	old->u = new->u;
	old->v = new->v;
	old->surface = new->surface;
	old->i = new->i;
	old->j = new->j;
	return (1);
}
