/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:03:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 15:03:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	get_lc(char *f)
{
	int		fd;
	int		l;
	char	*dat;

	l = 0;
	if (!(fd = open(f, O_RDONLY)))
	{
		ft_putendl(ESCAPE_YODA);
		exit(2);
	}
	while (get_next_line(fd, &dat) > 0)
	{
		l++;
		free(dat);
	}
	if (l == 0)
		exit(100);
	if (dat)
		free(dat);
	close(fd);
	return (l);
}

int			count(const char *s)
{
	int		c;
	char	**sp;

	sp = ft_strsplit(s, ' ');
	c = 0;
	while (sp[c])
	{
		free(sp[c]);
		c++;
	}
	free(sp);
	return (c);
}

void		check_line(const char *str)
{
	int		i;
	char	**sp;

	i = 0;
	sp = ft_strsplit(str, ' ');
	if (!sp[0])
	{
		ft_putendl(ESCAPE_YODA);
		exit(13);
	}
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

void		load_file(char *f, t_wolf *w)
{
	char	*dat;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(f, O_RDONLY)) < 0)
	{
		ft_putendl(ESCAPE_YODA);
		exit(3);
	}
	w->h = get_lc(f);
	w->m = (char **)malloc(sizeof(char *) * w->h);
	while (i < w->h)
	{
		get_next_line(fd, &dat);
		check_line(dat);
		w->m[i++] = dat;
		dat = NULL;
	}
	close(fd);
	w->w = count(w->m[0]);
	if (w->h < 1 && w->w < 1)
		exit(4);
}
