/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:27:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:27:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		draw_mini(t_wolf *w)
{
	float	x;
	float	y;

	x = (w->wi.c_w / 2.5f);
	while (x < w->wi.c_w / 2 + (w->wi.c_w / 10))
		put_pixel(x++, w->wi.c_h / 2, 0x000000, w);
	y = (w->wi.c_h / 2.5f);
	while (y < w->wi.c_h / 2 + (w->wi.c_h / 10))
		put_pixel(w->wi.c_w / 2, y++, 0x000000, w);
	return (0);
}
