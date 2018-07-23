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
# include "../libft/includes/libft.h"

# define ESCAPE_YODA	"Hmm... Fucked you did"

# define A				0
# define S				1
# define D				2
# define W				3
# define ESC			53
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_DOWN		125
# define ARROW_UP		126
# define SPACE			49

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
	t_winfo				wi;
}						t_wolf;

void					load_file(char *f, t_wolf *w);

int						key_press_hook(int key, t_wolf *w);
int						exit_hook(int but, t_wolf *w);
int						draw_back(t_wolf *w);

#endif
