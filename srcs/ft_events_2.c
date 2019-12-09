/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:48:29 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/05 20:01:28 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int			ft_delete_object(t_object **list, t_object **to_delete)
{
	t_object	*temp;
	t_object	*next;

	temp = *list;
	if (temp == *to_delete)
	{
		if (temp->cont != NULL)
			ft_free_conts(to_delete);
		*list = temp->next;
		free(temp->name);
		free(temp);
		*to_delete = NULL;
		return (1);
	}
	while (temp)
	{
		if (temp->next && temp->next == *to_delete)
			break ;
		temp = temp->next;
	}
	next = temp->next->next;
	free(temp->next);
	temp->next = next;
	*to_delete = NULL;
	return (2);
}

void		ft_select_obj(t_ptr *p, int col, int row)
{
	t_ray		r;

	r = ft_get_ray(&PS->cam, (double)(col + 0.5) / IMG_WIDTH,
			(double)(row + 0.5) / IMG_HEIGHT);
	if (ft_hit(PS, r, I(0.0001, DBL_MAX), &PS->record))
		PS->curr_object = PS->record.curr_obj;
	else
		PS->curr_object = NULL;
}

void		ft_selected_event(int key, t_ptr *p)
{
	if (key == MLX_KEY_X && PSC != NULL)
		ft_rot_obj(p, ft_rot_x);
	if (key == MLX_KEY_Y && PSC != NULL)
		ft_rot_obj(p, ft_rot_y);
	if (key == MLX_KEY_Z && PSC != NULL)
		ft_rot_obj(p, ft_rot_z);
	if (key == MLX_KEY_S)
		PS->speed *= p->inc_dec > 0 ? 1.3 : 1.0 / 1.3;
	if (key == MLX_KEY_A && !(p->inc_dec < 0 && PS->anti_a == 1.0))
		PS->anti_a = p->inc_dec > 0 ? PS->anti_a * 2.0 : PS->anti_a / 2.0;
}

int			ft_menu_event(int key, t_ptr *p)
{
	if (key == MLX_KEY_O && p->inc_dec == 1)
		PS->theta = PS->theta + 2.5 < 180.0 ? PS->theta + 2.5 : -180.0;
	if (key == MLX_KEY_O && p->inc_dec == -1)
		PS->theta = PS->theta - 2.5 > -180.0 ? PS->theta - 2.5 : 180.0;
	if (key == MLX_KEY_ENTER)
		p->inc_dec = p->inc_dec == 1 ? -1 : 1;
	return (RE_MAIN(key));
}
