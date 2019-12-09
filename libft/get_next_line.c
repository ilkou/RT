/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:50:38 by oouklich          #+#    #+#             */
/*   Updated: 2018/12/22 16:04:28 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*dest[4864];
	char		src[BUFF_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	if (fd == -1 || line == NULL || read(fd, src, 0) < 0)
		return (-1);
	if (dest[fd] == NULL)
		dest[fd] = ft_strnew(1);
	while ((ret = read(fd, src, BUFF_SIZE)) > 0)
	{
		src[ret] = '\0';
		dest[fd] = ft_strjoin(dest[fd], src);
		if (ft_strchr(src, '\n'))
			break ;
	}
	if (!(ft_strlen(dest[fd])))
		return (0);
	while (dest[fd][i] && dest[fd][i] != '\n')
		i++;
	*line = ft_strsub(dest[fd], 0, i);
	dest[fd] = ft_strdup(dest[fd] + i + 1);
	return (1);
}
