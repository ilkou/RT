/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 23:17:00 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:17:47 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_vector	*ft_perlin_generate(void)
{
	t_vector	*p;
	t_vector	random;
	int			i;

	i = -1;
	if (!(p = (struct s_vector*)malloc(256 * sizeof(struct s_vector))))
		ft_perror_exit();
	while (++i < 256)
	{
		random.v1 = 2 * ft_rand48() - 1;
		random.v2 = 2 * ft_rand48() - 1;
		random.v3 = 2 * ft_rand48() - 1;
		p[i] = ft_normalize(random);
	}
	return (p);
}

static void		ft_rand_swap(int *p, int n)
{
	int			rand_idx;
	int			i;

	i = n;
	while (--i > 0)
	{
		rand_idx = (int)(ft_rand48() * (i + 1));
		ft_swap_i(&p[i], &p[rand_idx]);
	}
	return ;
}

static int		*ft_perlin_generate_perm(void)
{
	int			*p;
	int			i;

	i = -1;
	if (!(p = (int*)malloc(256 * sizeof(int))))
		ft_perror_exit();
	while (++i < 256)
		p[i] = i;
	ft_rand_swap(p, 256);
	return (p);
}

void			ft_perlin_init(t_perlin *plin)
{
	plin->ranvec = ft_perlin_generate();
	plin->perm_x = ft_perlin_generate_perm();
	plin->perm_y = ft_perlin_generate_perm();
	plin->perm_z = ft_perlin_generate_perm();
}
