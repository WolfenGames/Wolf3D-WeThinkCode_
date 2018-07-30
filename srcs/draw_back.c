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

	x = -1;
	while (x++ < w->wi.c_w)
	{
		y = -1;
		while (y++ < w->wi.c_h)
		{
			if (y < w->wi.c_h / 2 - w->playerheight)
			{
				ny = y / (w->wi.c_h / 2 - w->playerheight);
				put_pixel(x, y, (y % 2) ? colour_grad(0x041266, 0xA5F1FF, ny) :
					0x000000, w);
			}
			else
			{
				ny = y / w->wi.c_h;
				put_pixel(x, y, (y % 2) ? colour_grad(0x56E000, 0x017f07, ny) :
					0x0000000, w);
			}
		}
	}
	return (0);
}
