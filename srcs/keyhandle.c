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
	if (key == ESC)
		exit_hook(key, w);
	draw(w);
	return (0);
}

int		exit_hook(int but, t_wolf *w)
{
	(void)w;
	(void)but;
	exit(0);
	return (0);
}
