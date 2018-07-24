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


int		key_press_hook(int key, t_wolf *w)
{
	double		angle;

	angle = arctorad(4.f);
	if (key == ESC)
		exit_hook(key, w);
	if (key == W)
	{
		if (w->pnts[(int)(w->p.x + w->p.dirx * 0.1f)][(int)(w->p.y)].type == 0)
			w->p.x += w->p.dirx * 0.5f;
		if (w->pnts[(int)(w->p.x)][(int)(w->p.y + w->p.diry * 0.1f)].type == 0)
			w->p.y += w->p.diry * 0.5f;
	}if (key == S)
	{
		if (w->pnts[(int)(w->p.x - w->p.dirx * 0.1f)][(int)(w->p.y)].type == 0)
			w->p.x -= w->p.dirx * 0.5f;
		if (w->pnts[(int)(w->p.x)][(int)(w->p.y - w->p.diry * 0.1f)].type == 0)
			w->p.y -= w->p.diry * 0.5f;
	}
	if (key == D)
	{
		double oldDirX = w->p.dirx;
		w->p.dirx = w->p.dirx * cos(-angle) - w->p.diry * sin(-angle);
		w->p.diry = oldDirX * sin(-angle) + w->p.diry * cos(-angle);
		double oldPlanex = w->panex;
		w->panex = w->panex * cos(-angle) - w->paney * sin(-angle);
		w->paney = oldPlanex * sin(-angle) + w->paney * cos(-angle);
	}
	if (key == A)
	{
		double oldDirX = w->p.dirx;
		w->p.dirx = w->p.dirx * cos(angle) - w->p.diry * sin(angle);
		w->p.diry = oldDirX * sin(angle) + w->p.diry * cos(angle);
		double oldPlanex = w->panex;
		w->panex = w->panex * cos(angle) - w->paney * sin(1);
		w->paney = oldPlanex * sin(angle) + w->paney * cos(angle);
	}
	return (0);
}

int		exit_hook(int but, t_wolf *w)
{
	(void)w;
	(void)but;
	exit(0);
	return (0);
}
