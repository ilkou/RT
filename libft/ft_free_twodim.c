/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_twodim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:09:28 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/14 16:26:43 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_twodim(char ***to)
{
	char	**to_free;
	int		i;

	i = 0;
	to_free = *to;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
