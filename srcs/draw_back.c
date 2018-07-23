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

int		colour_grad(int col1, int col2, float r)
{
	float	b_col1[3];
	float	b_col2[3];
	int		ret;

	b_col1[0] = (col1 & 0xff0000) / 0x10000;
	b_col1[1] = (col1 & 0xff00) / 0x100;
	b_col1[2] = (col1 & 0xff);
	b_col2[0] = (col2 & 0xff0000) / 0x10000;
	b_col2[1] = (col2 & 0xff00) / 0x100;
	b_col2[2] = (col2 & 0xff);
	ret = b_col2[0] * r + b_col1[0] * (1 - r);
	ret *= 0x100;
	ret += b_col2[1] * r + b_col1[1] * (1 - r);
	ret *= 0x100;
	ret += b_col2[2] * r + b_col1[2] * (1 - r);
	return (ret);
}

void	put_pixel(float x, float y, int col, t_wolf *w)
{
	if (x > 0 && x < w->wi.c_w && y > 0 && y < w->wi.c_h)
	{
		*(unsigned int *)(w->dat + ((int)x * w->bpp) + ((int)y * w->sl)) = col;
	}
}

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
		while (y < w->wi.c_h + 1)
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
