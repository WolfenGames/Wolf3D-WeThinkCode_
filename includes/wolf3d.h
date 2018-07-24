/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 06:25:34 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/23 06:25:35 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define ESCAPE_YODA	"Hmm... Fucked you did"

# define A				0
# define S				1
# define D				2
# define W				13
# define ESC			53
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_DOWN		125
# define ARROW_UP		126
# define SPACE			49

typedef struct			s_ray
{
	double				x;
	double				y;
	double				deltax;
	double				deltay;
}						t_ray;
typedef struct			s_player
{
	double				x;
	double				y;
	double				dirx;
	double				diry;
}						t_player;

typedef struct			s_objects
{
	int					type;
}						t_objects;

typedef struct			s_winfo
{
	float				c_w;
	float				c_h;
	char				*wn;
}						t_winfo;

typedef struct			s_wolf
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*dat;
	double				panex;
	double				paney;
	int					bpp;
	int					sl;
	int					endn;
	char				**m;
	int					w;
	int					h;
	int					bbox;
	float				wallsize;
	float				playerheight;
	float				rw;
	float				fov;
	t_bool				showray;
	t_winfo				wi;
	t_objects			**pnts;
	t_player			p;
}						t_wolf;

void					new_image(t_wolf *w);
void					load_file(char *f, t_wolf *w);
void					free_points(t_wolf *w, t_objects **o);
void					mapify(t_wolf *w, t_objects ***poofy);
void					put_pixel(float x, float y, int col, t_wolf *w);
void					window_init(void);
void					error_load(t_wolf *w);

int						colour_grad(int col1, int col2, float r);
int						key_press_hook(int key, t_wolf *w);
int						exit_hook(int but, t_wolf *w);
int						draw_mini(t_wolf *w);
int						draw_back(t_wolf *w);
int						ray_test(t_wolf *w);

float					arctorad(float a);
float					dist(t_ray a, t_ray b);

#endif
