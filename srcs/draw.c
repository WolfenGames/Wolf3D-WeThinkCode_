/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:40:36 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/30 14:40:37 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		get_image_col(t_tex *t, double x, double y)
{
	int		i;

	x *= t->ww;
	x = (int)x;
	y *= t->wh;
	y = (int)y;
	i = x + y * t->ww;
	return (t->dat[i]);
}

void	draw_col(int x, t_wolf *w, t_ray *r, int d[2])
{
	double	y;
	double	cy;

	y = 0;
	while (y < w->wi.c_h)
	{
		if (y < d[0] && y > d[1])
		{
			cy = (y - (double)d[0]) / ((double)d[1] - (double)d[0]);
			put_pixel(x, y,
						get_image_col(
							&w->t[ABS(w->pnts[r->mx][r->my].type) - 1],
							w->xslice, cy), w);
		}
		y++;
	}
}
