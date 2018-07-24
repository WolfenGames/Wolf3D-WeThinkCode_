/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:27:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:27:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_block(int xx, int yy, int off, int col, t_wolf *w)
{
	put_pixel(xx + off, yy + off, col, w);
}

int		draw_cross(t_wolf *w)
{
	int		x;
	int		y;

	x = 0;
	while (x < w->wi.c_w)
	{
		put_pixel(x, w->wi.c_h / 2, 0x000000, w);
		x++;
	}
	y = 0;
	while (y < w->wi.c_h)
	{
		put_pixel(w->wi.c_w / 2, y, 0x000000, w);
		y++;
	}
}

int		draw_mini(t_wolf *w)
{
	int		x;
	int		y;

	x = 0;
	while (x < w->w)
	{
		y = 0;
		while (y < w->h)
		{
			if (w->pnts[x][y].type == 1)
				draw_block(x, y, 10, 0xFF0000, w);
			 else if (w->pnts[x][y].type == 0)
				draw_block(x, y, 10, 0xA40F0F, w); 
			y++;
		}
		x++;
	}
	draw_cross(w);
	return (0);
}
