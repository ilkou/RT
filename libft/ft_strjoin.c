/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:55:44 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/18 18:31:43 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*frch;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	frch = (char*)malloc(sizeof(char*) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(frch))
		return (NULL);
	while (s1[i] != '\0')
	{
		frch[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		frch[i] = s2[j];
		i++;
		j++;
	}
	frch[i] = '\0';
	return (frch);
}
