/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:27:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:27:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		draw_back(t_wolf *w)
{
	int		x;
	int		y;
	float	ny;

	mlx_clear_window(w->mlx, w->win);
	x = 0;
	while (x < w->wi.c_w)
	{
		y = 0;
		while (y < w->wi.c_h)
		{
			if (y < w->wi.c_h / 2 + w->playerheight)
			{
				ny = y / (w->wi.c_h / 2 + w->playerheight);
				put_pixel(x, y, colour_grad(0x041266, 0xA5F1FF, ny), w);
			}
			else
			{
				ny = y / w->wi.c_h;
				put_pixel(x, y, colour_grad(0x56E0000, 0x017f07, ny), w);
			}
			y++;
		}
		x++;
	}
	return (0);
}
