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

int		update(t_wolf *w)
{
	new_image(w);
	draw_back(w);
	ray_test(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
	w->rotspeed = .2f;
	w->movespeed = 1.f;
	return (0);
}

void	check_tex(void)
{
	if (open("tex/colorstone.xpm", O_RDONLY) < 0 ||
		open("tex/bluestone.xpm", O_RDONLY) < 0 ||
		open("tex/greystone.xpm", O_RDONLY) < 0 ||
		open("tex/mossy.xpm", O_RDONLY) < 0 ||
		open("tex/wood.xpm", O_RDONLY) < 0)
	{
		ft_putendl("Valid xpm please...");
		exit(12);
	}
}

void	load_tex(t_wolf *w)
{
	w->t[0].img = (unsigned int *)mlx_xpm_file_to_image(w->mlx,
										"tex/colorstone.xpm",
										&w->t[0].ww, &w->t[0].wh);
	w->t[0].dat = (unsigned int *)mlx_get_data_addr(w->t[0].img, &w->t[0].b,
										&w->t[0].b, &w->t[0].b);
	w->t[1].img = (unsigned int *)mlx_xpm_file_to_image(w->mlx,
										"tex/bluestone.xpm",
										&w->t[1].ww, &w->t[1].wh);
	w->t[1].dat = (unsigned int *)mlx_get_data_addr(w->t[1].img, &w->t[1].b,
										&w->t[1].b, &w->t[1].b);
	w->t[2].img = (unsigned int *)mlx_xpm_file_to_image(w->mlx,
										"tex/greystone.xpm",
										&w->t[2].ww, &w->t[2].wh);
	w->t[2].dat = (unsigned int *)mlx_get_data_addr(w->t[2].img, &w->t[2].b,
										&w->t[2].b, &w->t[2].b);
	w->t[3].img = (unsigned int *)mlx_xpm_file_to_image(w->mlx,
										"tex/mossy.xpm",
										&w->t[3].ww, &w->t[3].wh);
	w->t[3].dat = (unsigned int *)mlx_get_data_addr(w->t[3].img, &w->t[3].b,
										&w->t[3].b, &w->t[3].b);
	w->t[4].img = (unsigned int *)mlx_xpm_file_to_image(w->mlx,
										"tex/wood.xpm",
										&w->t[4].ww, &w->t[4].wh);
	w->t[4].dat = (unsigned int *)mlx_get_data_addr(w->t[4].img, &w->t[4].b,
										&w->t[4].b, &w->t[4].b);
}

void	window_init(char *fn)
{
	t_wolf	*w;

	w = (t_wolf *)malloc(sizeof(t_wolf));
	w->wi.wn = "wolf3D - Win";
	w->wi.c_h = 400;
	w->wi.c_w = 800;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->wi.c_w, w->wi.c_h, w->wi.wn);
	load_file(fn, w);
	line_length(w);
	check_tex();
	load_tex(w);
	mapify(w, &w->pnts);
	w->playerheight = 32;
	w->p.dirx = -1;
	w->p.diry = 0;
	w->panex = 0;
	w->paney = 0.66f;
	set_hooks(w);
	mlx_loop_hook(w->mlx, update, w);
	mlx_loop(w->mlx);
}
