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

void	draw_col(int x, int col, t_wolf *w, int d[2])
{
	int		y;

	y = 0;
	while (y < w->wi.c_h)
	{
		if (y < d[0] + w->playerheight && y > d[1] - w->playerheight)
			put_pixel(x, y, col, w);
		y++;
	}
}

void	set_ray_dir_step(t_ray *r, t_wolf *w)
{
	if (r->raydx < 0)
	{
		r->stepx = -1;
		r->sx = (w->p.x - r->mx) * r->dx;
	}
	else
	{
		r->stepx = 1;
		r->sx = (r->mx + 1.0 - w->p.x) * r->dx;
	}
	if (r->raydy < 0)
	{
		r->stepy = -1;
		r->sy = (w->p.y - r->my) * r->dy;
	}
	else
	{
		r->stepy = 1;
		r->sy = (r->my + 1.0 - w->p.y) * r->dy;
	}
}

int		ray_hit(t_ray *r, t_wolf *w)
{
	int		hit;

	hit = 0;
	w->dist = 0;
	while (hit == 0 && w->dist < 100)
	{
		if (r->sx < r->sy)
		{
			r->side = 0;
			r->sx += r->dx;
			r->mx += r->stepx;
		}
		else
		{
			r->side = 1;
			r->sy += r->dy;
			r->my += r->stepy;
		}
		if (ray_in_map(r, w) && w->pnts[r->mx][r->my].type > 0)
			hit = 1;
		w->dist++;
	}
	return (hit);
}

void	wall_stuff(t_ray *r, t_wolf *w)
{
	int		lh;
	int		ds;
	int		de;
	int		d[2];

	lh = (int)(w->wi.c_h / r->pwalld);
	lh *= 2;
	ds = (-lh / 2) + (w->wi.c_h / 2);
	if (ds < 0)
		ds = 0;
	de = (lh / 2) + (w->wi.c_h / 2);
	if (de >= w->wi.c_h)
		de = w->wi.c_h - 1;
	d[0] = de;
	d[1] = ds;
	(w->dist < 10) ? draw_col(r->col,
				get_col_type(w->pnts[r->mx][r->my].type, r),
				w, d) :
				draw_col(r->col, (w->pnts[r->mx][r->my].type >> 1) | 0x666666,
				w, d);
}

int		ray_test(t_wolf *w)
{
	t_ray	r;

	r.col = w->wi.c_w;
	while (r.col > 0)
	{
		r.hit = 0;
		r.side = 0;
		r.cam_x = 2 * r.col / (double)w->wi.c_w - 1;
		r.raydx = w->p.dirx + w->panex * r.cam_x;
		r.raydy = w->p.diry + w->paney * r.cam_x;
		r.mx = (int)w->p.x;
		r.my = (int)w->p.y;
		r.dx = ABS(1 / r.raydx);
		r.dy = ABS(1 / r.raydy);
		set_ray_dir_step(&r, w);
		if (ray_hit(&r, w) == 1)
		{
			r.pwalld = (r.side == 0) ?
							(r.mx - w->p.x + (1 - r.stepx) / 2) / r.raydx :
							(r.my - w->p.y + (1 - r.stepy) / 2) / r.raydy;
			wall_stuff(&r, w);
		}
		r.col--;
	}
	return (0);
}
