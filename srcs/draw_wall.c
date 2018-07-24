/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:47:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/23 11:47:45 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_col(int x, int col, t_wolf *w, double len, int ds, int de)
{
	int		y;
	
	y = 0;
	while (y < w->wi.c_h)
	{
		if (y < de + w->playerheight && y > ds - w->playerheight)
			put_pixel(x, y, col, w);
		y++;
	}
}

int		get_col_type(int t, int side)
{
	if (side)
	{
		if (t == 1)
			return (0xF000F0);
		if (t == 2)
			return (0xF00000);
		if (t == 3)
			return (0xAFAFAF);
		if (t == 4)
			return (0xFAFAFA);
		if (t == 5)
			return (0xFF0000);
	}else
	{
		if (t == 1)
			return (0xFF00FF);
		if (t == 2)
			return (0xFF0000);
		if (t == 3)
			return (0x0F0F0F);
		if (t == 4)
			return (0xF0F0F0);
		if (t == 5)
			return (0x0000FF);
	}
	return (0xFFFFFF);
}

int		ray_test(t_wolf *w)
{
	//struct stuff
	double	cam_x;
	int		col;
	double	raydx;
	double	raydy;
	double	pwalld;
	int		side;
	int		stepx;
	int		stepy;
	int		hit;
	double	sx;
	double	sy;
	double	dx;
	double	dy;
	int		mx;
	int		my;

	col = w->wi.c_w;
	while (col > 0)
	{
		hit = 0;
		side = 0;
		cam_x = 2 * col / (double)w->wi.c_w - 1;
		raydx = w->p.dirx + w->panex * cam_x;
		raydy = w->p.diry + w->paney * cam_x;
		mx = (int)w->p.x;
		my = (int)w->p.y;
		dx = ABS(1 / raydx);
		dy = ABS(1 / raydy);
		//rat_dir && step
		if (raydx < 0)
		{
			stepx = -1;
			sx = (w->p.x - mx) * dx;
		}
		else
		{
			stepx = 1;
			sx = (mx + 1.0 - w->p.x) * dx;
		}
		if (raydy < 0)
		{
			stepy = -1;
			sy = (w->p.y - my) * dy;
		}
		else
		{
			stepy = 1;
			sy = (my + 1.0 - w->p.y) * dy;
		}
		//Hit test
		while (hit == 0)
		{
			if (sx < sy)
			{
				sx += dx;
				mx += stepx;
				side = 0;
			}
			else
			{
				sy += dy;
				my += stepy;
				side = 1;
			}
			if (w->pnts[mx][my].type > 0)
				hit = 1;
		}
		//side val
		if (side == 0)	pwalld = (mx - w->p.x + (1 - stepx) /2 ) / raydx;
		else			pwalld = (my - w->p.y + (1 - stepy) / 2) / raydy; 

		//TODO: Sort later
		int		lh;
		int		ds;
		int		de;

		lh = (int)(w->wi.c_h / pwalld);
		ds = (-lh / 2) + (w->wi.c_h / 2);
		if (ds < 0) ds = 0;
		de = (lh / 2) + (w->wi.c_h / 2);
		if (de >= w->wi.c_h) de = w->wi.c_h - 1;
			draw_col(col, get_col_type(w->pnts[mx][my].type, side), w, lh, ds, de);
		col--;
	}
	return (0);
}
