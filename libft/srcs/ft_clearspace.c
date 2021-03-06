/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:19:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/13 16:54:11 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_clearspace(const char *s, int c)
{
	if (c == 0)
		while (s[c] == ' ' || s[c] == '\t' || c[s] == '\n' || c[s] == '\r'
					|| c[s] == '\v')
			c++;
	else
		while (s[c] == ' ' || s[c] == '\t' || s[c] == '\n' || s[c] == '\0')
			c--;
	return (c);
}
