/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/04/04 20:07:17 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_pos(t_coord *c, size_t x, size_t y)
{
	c->x = x;
	c->y = y;
}

static bool	right_component_amt(t_env *env, size_t y, size_t x)
{
	bool	seen_exit;
	bool	seen_pony;

	seen_exit = false;
	seen_pony = false;
	if (env->map.ptr[y][x] == EXIT)
	{
		if (seen_exit == true)
			return (ft_puterr
				("too many exits in this map, only one allowed\n"), false);
		set_pos(&(env->map.pos.exit), x, y);
		seen_exit = true;
	}
	else if (env->map.ptr[y][x] == PONY)
	{
		if (seen_pony == true)
			return (ft_puterr
				("too many ponies in this map, only one allowed\n"), false);
		set_pos(&(env->map.pos.pony), x, y);
		seen_pony = true;
	}
	else if (env->map.ptr[y][x] == TREASURE)
		env->map.pos.treasure_num++;
	return (true);
}

static bool	pos(t_env *env)
{
	size_t	x;
	size_t	y;

	env->map.pos.taken_treasure = 0;
	env->map.pos.treasure_num = 0;
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			right_component_amt(env, y, x);
			x++;
		}
		y++;
	}
	if (env->map.pos.treasure_num == 0)
		return (ft_puterr
			("too few treasures in this map, at least one needed\n"), false);
	return (true);
}

bool	parse(t_env *env, const char *path)
{
	size_t	size;
	size_t	n_line;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
	{
		ft_puterr("not the right filetype, a .ber file is needed\n");
		return (false);
	}
	n_line = load_map(env, path);
	if (!n_line)
		return (false);
	env->map.ptr = (t_cell **)malloc(sizeof(t_cell *) * (n_line + 1));
	if (!env->map.ptr)
		return (false);
	env->map.mapcopy = (t_cell **)malloc(sizeof(t_cell *) * (n_line + 1));
	if (!env->map.mapcopy)
		return (false);
	if (load_map(env, path) <= 0)
		return (false);
	return (pos(env));
}
