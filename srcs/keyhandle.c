/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:54:12 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:54:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	rotate(int key, t_wolf *w)
{
	double	olddirx;
	double	oldplanex;
	double	angle;

	angle = 0.1f;
		olddirx = w->p.dirx;
		oldplanex = w->panex;
	if (key == D || key == ARROW_RIGHT)
	{
		w->p.dirx = w->p.dirx * cos(-angle) - w->p.diry * sin(-angle);
		w->p.diry = olddirx * sin(-angle) + w->p.diry * cos(-angle);
		w->panex = w->panex * cos(-angle) - w->paney * sin(-angle);
		w->paney = oldplanex * sin(-angle) + w->paney * cos(-angle);
	}
	if (key == A || key == ARROW_LEFT)
	{
		w->p.dirx = w->p.dirx * cos(angle) - w->p.diry * sin(angle);
		w->p.diry = olddirx * sin(angle) + w->p.diry * cos(angle);
		w->panex = w->panex * cos(angle) - w->paney * sin(angle);
		w->paney = oldplanex * sin(angle) + w->paney * cos(angle);
	}
}

void	move_x_y(int key, t_wolf *w)
{
	if ((key == W || key == ARROW_UP))
	{
		if (w->pnts[(int)(w->p.x + w->p.dirx * 1.1f)][(int)(w->p.y)].type < 1)
			w->p.x += w->p.dirx * 1.f;
		if (w->pnts[(int)(w->p.x)][(int)(w->p.y + w->p.diry * 1.1f)].type < 1)
			w->p.y += w->p.diry * 1.f;
	}
	if ((key == S || key == ARROW_DOWN))
	{
		if (w->pnts[(int)(w->p.x - w->p.dirx * 1.1f)][(int)(w->p.y)].type < 1)
			w->p.x -= w->p.dirx * 1.f;
		if (w->pnts[(int)(w->p.x)][(int)(w->p.y - w->p.diry * 1.1f)].type < 1)
			w->p.y -= w->p.diry * 1.f;
	}

}

int		key_press_hook(int key, t_wolf *w)
{
	if (key == ESC)
		exit_hook(key, w);
	if (key == NUM_PLUS)
		w->fog += 1;
	if (key == NUM_MINUS)
		w->fog -= 1;
	move_x_y(key, w);
	rotate(key, w);
	return (0);
}

int		exit_hook(int but, t_wolf *w)
{
	(void)w;
	(void)but;
	exit(0);
	return (0);
}
