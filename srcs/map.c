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

/* char		ft_char_toupper(char c)
{
	int		ic;

	ic = ft_toupper(c);
	return (ic);
}

 t_points	new_point(int x, char *y, int z, t_map *m)
{
	t_points	p;
	char		*found;
	char		*t;

	p.z = x - (m->h / 2);
	p.y = ft_atoi(y);
	p.x = z - (m->w / 2);
	found = ft_strchr(y, 'x');
	if (found)
	{
		t = ft_strmap(found + 1, ft_char_toupper);
		p.c = ft_atoi_base(t, 16);
		free(t);
	}
	else if (p.y < 9)
		p.c = (p.y > 1) ? 0xFF00FF : 0xFFFF00;
	else
		p.c = (p.y > 9) ? 0x00FF00 : 0x0000FF;
	return (p);
}

void		free_points(t_map *m, t_points **p)
{
	long int	i;

	i = -1;
	while (++i < m->h)
	{
		free(p[i]);
	}
	free(p);
	p = NULL;
} */

void		mapify(t_wolf *w)
{
	long int	x;
	long int	y;
	char		**sp;

	x = 0;
	while (x < w->h)
	{
		y = 0;
		sp = ft_strsplit(w->m[x], ' ');
		while (y < w->w)
		{
			if (ft_strlen(sp[y]) == 0)
			{
				ft_putendl(ESCAPE_YODA);
				exit(11);
			}
			free(sp[y]);
			y++;
		}
		free(sp);
		x++;
	}
}
