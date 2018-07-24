/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:25:51 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/23 08:25:52 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pixel(float x, float y, int col, t_wolf *w)
{
	if (x >= 0 && x < w->wi.c_w && y >= 0 && y < w->wi.c_h)
	{
		*(unsigned int *)(w->dat + ((int)x * w->bpp) + ((int)y * w->sl)) = col;
	}
}

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

float	dist(t_ray a, t_ray b)
{
	float	x;
	float	y;

	x = pow((b.x - a.x), 2);
	y = pow((b.y - a.y), 2);
	return (sqrt(x + y));
}

void	new_image(t_wolf *w)
{
	w->img = mlx_new_image(w->mlx, w->wi.c_w, w->wi.c_h);
	w->dat = mlx_get_data_addr(w->img, &w->bpp, &w->sl, &w->endn);
	w->bpp /= 8;
}
