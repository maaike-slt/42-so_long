/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:08:38 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 16:02:13 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	single_component(
	t_env *env, t_coord c, bool *seen_exit, bool *seen_pony)
{
	if (env->map.ptr[c.y][c.x] == EXIT)
	{
		if (*seen_exit == true)
			return (ft_puterr
				("too many exits in this map, only one allowed\n"), false);
		env->map.pos.exit = c;
		*seen_exit = true;
	}
	else if (env->map.ptr[c.y][c.x] == PONY)
	{
		if (*seen_pony == true)
			return (ft_puterr
				("too many ponies in this map, only one allowed\n"), false);
		env->map.pos.pony = c;
		*seen_pony = true;
	}
	else if (env->map.ptr[c.y][c.x] == TREASURE)
		env->map.pos.treasure_num++;
	return (true);
}

static bool	component_count(t_env *env)
{
	t_coord	c;
	bool	seen_exit;
	bool	seen_pony;

	seen_exit = false;
	seen_pony = false;
	env->map.pos.taken_treasure = 0;
	env->map.pos.treasure_num = 0;
	c.y = 0;
	while (c.y < env->map.h)
	{
		c.x = 0;
		while (c.x < env->map.w)
		{
			if (!single_component(env, c, &seen_exit, &seen_pony))
				return (false);
			c.x++;
		}
		c.y++;
	}
	if (env->map.pos.treasure_num == 0)
		return (ft_puterr
			("too few treasures in this map, at least one needed\n"), false);
	return (true);
}

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
			&& line[i] != TREASURE && line[i] != EXIT && line[i] != FOE)
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
	if (!component_count(env))
		return (false);
	return (all_reachable(env));
}
