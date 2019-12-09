/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:03:08 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/18 21:05:08 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char **argv, int i, int j)
{
	char	*aide;

	aide = argv[i];
	argv[i] = argv[j];
	argv[j] = aide;
}

static void	afficher(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		ft_sort_params(int argc, char **argv)
{
	int		i[4];

	i[0] = 0;
	while (++i[0] < argc - 1)
	{
		i[2] = i[0];
		while (++i[2] < argc)
		{
			i[1] = 0;
			i[3] = 0;
			while ((argv[i[0]][i[1]] && argv[i[2]][i[1]]) && i[3] == 0)
			{
				if (argv[i[0]][i[1]] == argv[i[2]][i[1]])
					i[1]++;
				else
					i[3] = 1;
				if (argv[i[0]][i[1]] > argv[i[2]][i[1]])
					ft_swap(argv, i[0], i[2]);
			}
		}
	}
	afficher(argc, argv);
}
