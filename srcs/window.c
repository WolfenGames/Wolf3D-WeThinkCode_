/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:46:52 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:46:54 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	set_hooks(t_wolf *w)
{
	mlx_do_key_autorepeaton(w->mlx);
	mlx_hook(w->win, 2, 0, key_press_hook, w);
	mlx_hook(w->win, 17, 0, exit_hook, w);
}

int		expose(t_wolf *w)
{
	new_image(w);
	draw_back(w);
	ray_test(w);
	draw_mini(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
	return (0);
}

int		update(t_wolf *w)
{
	new_image(w);
	draw_back(w);
	ray_test(w);
	draw_mini(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
	return (0);
}

void	window_init(void)
{
	t_wolf	*w;

	w = (t_wolf *)malloc(sizeof(t_wolf));
	w->wi.wn = "wolf3D - Win";
	w->wi.c_h = 400;
	w->wi.c_w = 800;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->wi.c_w, w->wi.c_h, w->wi.wn);
	load_file("./maps/test.wolf3d", w);
	mapify(w, &w->pnts);
	w->wallsize = 64;
	w->playerheight = 32;
	w->fov = 60;
	w->showray = FALSE;
	w->p.dirx = -1;
	w->p.diry = 0;
	w->panex = 0;
	w->paney = 0.33;
	set_hooks(w);
	mlx_expose_hook(w->win, expose, w);
	mlx_loop_hook(w->mlx, update, w);
	mlx_loop(w->mlx);
}
