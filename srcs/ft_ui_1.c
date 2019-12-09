/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:41:09 by oouklich          #+#    #+#             */
/*   Updated: 2019/11/22 18:26:42 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int			ft_bg_col(int bg, int x, int y)
{
	if (bg && ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)))
		return (BG_COL_1);
	else if (bg && !((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)))
		return (BG_COL_2);
	else if (!bg && ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)))
		return (BG_COL_3);
	else
		return (BG_COL_4);
}

char		*ft_ctoa(t_color c)
{
	char	*ret;
	char	*r;
	char	*g;
	char	*b;

	r = ft_dtoa(c.r);
	g = ft_dtoa(c.g);
	b = ft_dtoa(c.b);
	ret = ft_mystrjoin(r, " ", 0);
	ret = ft_mystrjoin(ret, g, 2);
	ret = ft_mystrjoin(ret, " ", 0);
	ret = ft_mystrjoin(ret, b, 2);
	return (ret);
}

char		*ft_vtoa(t_vector v)
{
	char	*ret;
	char	*v1;
	char	*v2;
	char	*v3;

	v1 = ft_dtoa(v.v1);
	v2 = ft_dtoa(v.v2);
	v3 = ft_dtoa(v.v3);
	ret = ft_mystrjoin(v1, " ", 0);
	ret = ft_mystrjoin(ret, v2, 2);
	ret = ft_mystrjoin(ret, " ", 0);
	ret = ft_mystrjoin(ret, v3, 2);
	return (ret);
}

void		ft_menu_bar(t_ptr *p)
{
	MSP(p->mlx, p->win, FRAME + 10, FRAME + 10, COL1, "Selected: ");
	MSP(p->mlx, p->win, FRAME + 10, FRAME + 30, COL1, "Position: ");
	MSP(p->mlx, p->win, FRAME + 10, FRAME + 50, COL1, "Rotation: ");
	MSP(p->mlx, p->win, FRAME + 10, FRAME + 70, COL1, "Color: ");
	MSP(p->mlx, p->win, FRAME + 10, FRAME + 90, COL1, "Size: ");
	MSP(p->mlx, p->win, FRAME + 310, FRAME + 10, COL1, "Cam Position: ");
	MSP(p->mlx, p->win, FRAME + 310, FRAME + 30, COL1, "[O]Rotation Angle: ");
	MSP(p->mlx, p->win, FRAME + 310, FRAME + 50, COL1, "[A]AntiAliasing: ");
	MSP(p->mlx, p->win, FRAME + 310, FRAME + 70, COL1, "[S]Speed: ");
	MSP(p->mlx, p->win, FRAME + 310, FRAME + 90, COL1, "[D]Delete object");
	MSP(p->mlx, p->win, FRAME + 640, FRAME + 10, COL1, "[Enter]");
	ft_display_properties(p);
	ft_display_moves(p);
	if (PS->curr_object == NULL)
		MSP(p->mlx, p->win, FRAME + 110, FRAME + 10, COL2, "No Object");
	else
		ft_object_selected(p);
}

void		ft_background(t_ptr *p)
{
	int			col;
	int			row;

	row = 0;
	while (row < WIN_HEIGHT)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			if (BG_COND(row, col))
				mlx_pixel_put(p->mlx, p->win, col, row,
						ft_bg_col(1, row / 5, col / 5));
			else
				mlx_pixel_put(p->mlx, p->win, col, row, ft_bg_col(0, row, col));
			col = BG_COND1(row, col) ? WIN_WIDTH - FRAME : col + 1;
		}
		row = BG_COND2(row, col) ? WIN_HEIGHT - FRAME : row + 1;
	}
	ft_menu_bar(p);
}
