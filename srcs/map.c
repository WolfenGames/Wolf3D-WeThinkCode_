/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:05:15 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/12 10:05:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

 char		ft_char_toupper(char c)
{
	int		ic;

	ic = ft_toupper(c);
	return (ic);
}

 t_objects	new_point(int x, int y, char *s, t_wolf *w)
{
	t_objects	p;

	(void)w;
	p.x = x;
	p.y = y;
	p.type = (ft_strequ(s, "1")) ? 1 : 0;
	return (p);
}

void		free_points(t_wolf *w, t_objects **o)
{
	long int	i;

	i = -1;
	while (++i < w->h)
	{
		free(o[i]);
	}
	free(o);
	o = NULL;
}

void		mapify(t_wolf *w, t_objects ***poofy)
{
	long int	x;
	long int	y;
	char		**sp;
	t_objects	**op;

	x = 0;
	op = (t_objects **)malloc(sizeof(t_objects *) * w->h);
	while (x < w->h)
	{
		y = 0;
		op[x] = (t_objects *)malloc(sizeof(t_objects) * w->w);
		sp = ft_strsplit(w->m[x], ' ');
		while (y < w->w)
		{
			op[x][y] = new_point(x, y, sp[y], w);
			free(sp[y]);
			y++;
		}
		free(sp);
		x++;
	}
	*poofy = op;
}
