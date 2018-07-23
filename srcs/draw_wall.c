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

void	draw_col(int x, int col, t_wolf *w, double len)
{
	int		y;
	int		begin;
	int		end;

	len = 1 / len;
	begin = (int)(len * ((double)w->wi.c_h / 2.0f));
	end = w->wi.c_h / 2 + begin;
	begin = w->wi.c_h / 2 - begin;
	y = 0;
	while (y < w->wi.c_h)
	{
		if (y < end && y > begin)
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
	int		col;
	double	part;
	double	dir[2] = {0, 1};
	double	pane[2] = {0.9, 0};
	double	curry;
	double	currx;
	int		touch;
	int		hit;
	t_ray	ray;

	col = 0;
	touch = 0;
	while (col < w->wi.c_w)
	{
		hit = 0;
		part = (col / (w->wi.c_w / 2)) - 1;
		ray.x = dir[0] + (pane[0] * part);
		ray.y = dir[1] + (pane[1] * part);
		normalise(&ray);
		ray.deltax = ABS(1 / ray.x);
		ray.deltay = ABS(1 / ray.y);
		curry = ray.y < 0 ? ((w->p.y - (int)w->p.y) * ray.deltay) : (((int)w->p.y + (1 - w->p.y)) * ray.deltay);
		currx = ray.x < 0 ? ((w->p.x - (int)w->p.x) * ray.deltax) : (((int)w->p.x + (1 - w->p.x)) * ray.deltax);
		while (!hit || (hit == 2 && currx > curry) || (hit == 1 && curry > currx))
		{
			if (curry > currx)
			{
				currx += ray.deltax;
				if ((currx * ray.y + w->p.y) < w->w && (currx * ray.y + w->p.y) >= 0 && (currx * ray.x + w->p.x) < w->h && (currx * ray.x + w->p.x) >= 0)
					if (w->pnts[(int)(w->p.x + currx * ray.x)][(int)(w->p.y + currx * ray.y)].type == 1)
						if (!hit || hit == 1 && currx < curry)
							hit = 2;
			}
			else
			{
				curry += ray.deltay;
				if ((curry * ray.x + w->p.x) < w->h && (curry * ray.x + w->p.x) >= 0 && (curry * ray.y + w->p.y) < w->w && (curry * ray.y + w->p.y) >= 0)
					if (w->pnts[(int)(w->p.x + curry * ray.x)][(int)(w->p.y + curry * ray.y)].type == 1)
						if (!hit || hit == 2 && curry < currx)
							hit = 1;
			}
		}
		if (hit == 2)
			draw_col(col, 0xFF00FF, w, currx);
		else
			draw_col(col, 0x0000FF, w, curry);
		col++;
	}
	return (0);
}
