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

	angle = w->rotspeed;
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
	double	ms;

	ms = w->movespeed;
	if (w->p.x + w->p.dirx * ms > 0 && w->p.y + w->p.diry * ms > 0 &&
		w->p.x + w->p.dirx * ms < w->h && w->p.y + w->p.diry * ms < w->w)
	{
		if ((key == W || key == ARROW_UP))
		{
			if (w->pnts[(int)(w->p.x + w->p.dirx * ms)][(int)(w->p.y)].type < 1)
				w->p.x += w->p.dirx * ms;
			if (w->pnts[(int)(w->p.x)][(int)(w->p.y + w->p.diry * ms)].type < 1)
				w->p.y += w->p.diry * ms;
		}
	}
	if (w->p.x - w->p.dirx * ms > 0 && w->p.y - w->p.diry * ms > 0 &&
		w->p.x - w->p.dirx * ms < w->h && w->p.y - w->p.diry * ms < w->w)
	{
		if ((key == S || key == ARROW_DOWN))
		{
			if (w->pnts[(int)(w->p.x - w->p.dirx * ms)][(int)(w->p.y)].type < 1)
				w->p.x -= w->p.dirx * ms;
			if (w->pnts[(int)(w->p.x)][(int)(w->p.y - w->p.diry * ms)].type < 1)
				w->p.y -= w->p.diry * ms;
		}
	}
}

int		key_press_hook(int key, t_wolf *w)
{
	if (key == ESC)
		exit_hook(key, w);
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
