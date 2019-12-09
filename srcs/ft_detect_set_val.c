/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_set_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:13:13 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/11/18 19:21:38 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_object	*zero_x_case(t_object *new, t_object *old)
{
	new->i = old->i;
	new->j = old->j;
	new->rot = old->rot;
	new->size = old->size;
	new->height = old->height;
	new->weight = old->weight;
	return (new);
}

t_object	*one_x_case(t_object *new, t_object *old)
{
	new->i = old->i;
	new->j = old->rot;
	new->rot = old->j;
	new->size = old->size;
	new->height = old->weight;
	return (new);
}

t_object	*two_x_case(t_object *new, t_object *old)
{
	new->i = old->j;
	new->j = old->rot;
	new->rot = old->i;
	new->size = old->height;
	new->height = old->weight;
	return (new);
}

t_object	*three_x_case(t_object *new, t_object *old)
{
	new->i = old->rot;
	new->j = old->i;
	new->rot = old->j;
	new->size = old->height;
	new->height = old->size;
	return (new);
}

t_object	*four_x_case(t_object *new, t_object *old)
{
	new->i = old->rot;
	new->j = old->j;
	new->rot = old->i;
	new->size = old->height;
	new->height = old->size;
	return (new);
}
