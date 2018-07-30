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
		if (ray_in_map(r, w) && ABS(w->pnts[r->mx][r->my].type) > 0)
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
	ds = (-lh / 4) + (w->wi.c_h / 2) - w->playerheight;
	de = (lh / 4) + (w->wi.c_h / 2) - w->playerheight;
	d[0] = de;
	d[1] = ds;
	draw_col(r->col, w, r, d);
}

void	reset_ray(t_ray *r, t_wolf *w)
{
	r->hit = 0;
	r->side = 0;
	r->cam_x = 2 * r->col / (double)w->wi.c_w - 1;
	r->raydx = w->p.dirx + w->panex * r->cam_x;
	r->raydy = w->p.diry + w->paney * r->cam_x;
	r->mx = (int)w->p.x;
	r->my = (int)w->p.y;
	r->dx = ABS(1 / r->raydx);
	r->dy = ABS(1 / r->raydy);
}

int		ray_test(t_wolf *w)
{
	t_ray	r;

	r.col = w->wi.c_w;
	while (r.col >= 0)
	{
		reset_ray(&r, w);
		set_ray_dir_step(&r, w);
		if (ray_hit(&r, w) == 1)
		{
			r.pwalld = (r.side == 0) ?
							(r.mx - w->p.x + (1 - r.stepx) / 2) / r.raydx :
							(r.my - w->p.y + (1 - r.stepy) / 2) / r.raydy;
			w->xslice = (r.side == 1) ?
							(w->p.x + r.raydx * (r.pwalld)) :
							(w->p.y + r.raydy * (r.pwalld));
			w->xslice -= (int)w->xslice;
			wall_stuff(&r, w);
		}
		r.col--;
	}
	return (0);
}
