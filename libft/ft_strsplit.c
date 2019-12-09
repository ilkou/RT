/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:10:36 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/18 18:58:50 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(const char *str, int i, char c)
{
	int		size;

	size = 0;
	while (str[i] != c && str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static int		ft_w(const char *str, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			size++;
		}
	}
	return (size);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	k = 0;
	if (!(str) || !(dest = (char**)malloc((ft_w(str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (str[k])
	{
		while (str[k] == c && str[k])
			k++;
		if (str[k] && ft_w(str, c))
		{
			j = 0;
			if (!(dest[i] = (char*)malloc((ft_len(str, k, c) + 1))))
				return (NULL);
			while (str[k] != c && str[k])
				dest[i][j++] = str[k++];
			dest[i++][j] = '\0';
		}
	}
	dest[i] = 0;
	return (dest);
}
