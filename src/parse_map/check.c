/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:08:38 by msloot            #+#    #+#             */
/*   Updated: 2024/04/09 21:49:06 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_line(const char *line, size_t len, bool first_or_last)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((first_or_last == true || i == 0) && line[i] != WALL)
			return (ft_puterr("map has to be surrounded by walls\n"), false);
		else if ((first_or_last == true || i == len - 1) && line[i] != WALL)
			return (ft_puterr("map has to be surrounded by walls\n"), false);
		else if ((line[i] != WALL && line[i] != EMPTY && line[i] != PONY)
			&& line[i] != TREASURE && line[i] != EXIT)
			return (ft_puterr
				("this map is composed with an unvalid character\n"),
				false);
		i++;
	}
	if (i != len)
		return (ft_puterr
			("the given map does not have a rectangular shape\n"), false);
	return (true);
}

bool	check_map(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->map.h)
	{
		if (!check_line
			(env->map.ptr[i], env->map.w, i == 0 || i == env->map.h - 1))
			return (false);
		i++;
	}
	return (true);
}
