/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:11:11 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/19 08:11:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		line_length(t_wolf *w)
{
	long int	x;
	long int	y;
	int			z;
	char		**sp;

	x = 0;
	while (x < w->h)
	{
		y = 0;
		sp = ft_strsplit(w->m[x], ' ');
		while (y < w->w)
		{
			z = 0;
			while (sp[z])
				z++;
			if (z != w->w)
				exit(99);
			free(sp[y]);
			y++;
		}
		free(sp);
		x++;
	}
}

int			ray_in_map(t_ray *r, t_wolf *w)
{
	return (r->mx >= 0 && r->my >= 0 && r->mx < w->h && r->my < w->w);
}
