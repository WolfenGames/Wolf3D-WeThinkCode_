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
		if (y < de && y > ds)
			put_pixel(x, y, col, w);
		y++;
	}
}

void	normalise(t_ray *r)
{
	double	len;

	len = sqrt((r->y * r->y) + (r->x * r->x));
	r->y /= len;
	r->x /= len;
}

int		ray_test(t_wolf *w)
{
	double	cam_x;
	double	col;
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

	col = 0;
	while (col < w->wi.c_w)
	{
		hit = 0;
		side = 0;
		cam_x = 2 * col / (double)w->wi.c_h - 1;
		raydx = w->p.dirx + w->panex * cam_x;
		raydy = w->p.diry + w->paney * cam_x;
		mx = (int)w->p.x;
		my = (int)w->p.y;
		dx = ABS(1 / raydx);
		dy = ABS(1 / raydy);
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
			}
			if (w->pnts[mx][my].type == 1)
				hit = 1;
		}
		if (side == 0)	pwalld = (mx - w->p.x + (1 - stepx) /2 ) / raydx;
		else			pwalld = (my - w->p.y + (1 - stepy) / 2) / raydy; 

		//TODO: Sort later
		int		lh;
		int		ds;
		int		de;

		lh = (int)(w->wi.c_h / pwalld);
		ds = -lh / 2 + w->wi.c_h / 2;
		if (ds < 0) ds = 0;
		de = lh / 2 + w->wi.c_h / 2;
		if (de >= w->wi.c_h) de = w->wi.c_h - 1;
		if (side == 1)
			draw_col(col, 0xFF00FF, w, lh, ds, de);
		else
			draw_col(col, 0x00FF00, w, lh, ds, de);
		col++;
	}
	return (0);
}
