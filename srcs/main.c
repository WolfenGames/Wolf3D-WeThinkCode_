/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:43:47 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/10 14:43:48 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int ac, char **av)
{
	if (ac > 1 && ft_strequ(ft_strrchr(av[1], '.'), ".wolf3d"))
	{
		ft_putendl("Only first argument counts...");
		ft_putendl("Loading file");
		window_init(av[1]);
	}
	else
	{
		ft_putendl("FEED ME VALID FILES!!!!");
		ft_putendl("e.g		:: ./wolf3d maps/test.wolf3d");
	}
	return (0);
}
