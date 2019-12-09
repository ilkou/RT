/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:29:52 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/18 20:01:18 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*copy;
	size_t			len;
	unsigned int	start;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (!(start == ft_strlen(s)))
	{
		len = ft_strlen(s);
		len--;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		len++;
		copy = ft_strsub(s, start, (len - (size_t)start));
	}
	else
	{
		copy = malloc(sizeof(char));
		copy[0] = '\0';
	}
	return (copy);
}
