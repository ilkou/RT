/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:22:39 by oouklich          #+#    #+#             */
/*   Updated: 2019/08/15 17:07:57 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_rot_x(t_vector old, double theta)
{
	t_vector	new;

	new.v1 = old.v1;
	new.v2 = old.v2 * cos(theta) - old.v3 * sin(theta);
	new.v3 = old.v2 * sin(theta) + old.v3 * cos(theta);
	return (new);
}

t_vector	ft_rot_y(t_vector old, double theta)
{
	t_vector	new;

	new.v1 = old.v1 * cos(theta) + old.v3 * sin(theta);
	new.v2 = old.v2;
	new.v3 = -old.v1 * sin(theta) + old.v3 * cos(theta);
	return (new);
}

t_vector	ft_rot_z(t_vector old, double theta)
{
	t_vector	new;

	new.v1 = old.v1 * cos(theta) - old.v2 * sin(theta);
	new.v2 = old.v1 * sin(theta) + old.v2 * cos(theta);
	new.v3 = old.v3;
	return (new);
}

t_vector	ft_rotcam_y(t_vector old, double theta)
{
	t_vector	new;

	new.v1 = old.v1 * cos(theta) - old.v3 * sin(theta);
	new.v2 = old.v2;
	new.v3 = old.v1 * sin(theta) + old.v3 * cos(theta);
	return (new);
}

t_vector	ft_rotcam_x(t_vector old, double theta)
{
	t_vector	new;

	new.v1 = old.v1;
	new.v2 = old.v2 * cos(theta) - old.v3 * sin(theta);
	new.v3 = old.v2 * sin(theta) + old.v3 * cos(theta);
	return (new);
}
