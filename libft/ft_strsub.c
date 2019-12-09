/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:29:36 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/18 19:42:45 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fraiche;
	int				i;
	unsigned int	start_const;

	i = 0;
	start_const = start;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(&s[(size_t)start]) >= len)
	{
		if (!(fraiche = (char*)malloc((len + 1) * sizeof(char))))
			return (NULL);
		while ((size_t)start < len + start_const)
		{
			fraiche[i] = *((char*)s + (size_t)start);
			i++;
			start++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	else
		return (NULL);
}
