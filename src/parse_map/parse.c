/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/04/09 22:29:51 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	right_component_amt(
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

static bool	pos(t_env *env)
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
			if (!right_component_amt(env, c, &seen_exit, &seen_pony))
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

// put two functions above in check.c and call them in check_map
// thus, instead I return check_map instead of pos
// also, rename the shitty function names above

bool	parse(t_env *env, const char *path)
{
	size_t	size;
	ssize_t	line_count;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
		return (ft_puterr
			("not the right filetype, a .ber file is needed\n"), false);
	line_count = count_line(path);
	if (line_count <= 0)
		return (false);
	env->map.ptr = (t_cell **)malloc(sizeof(t_cell *) * (line_count + 1));
	if (!env->map.ptr)
		return (false);
	env->map.mapcopy = (t_cell **)malloc(sizeof(t_cell *) * (line_count + 1));
	if (!env->map.mapcopy)
		return (false);
	if (load_map(env, path) <= 0)
		return (false);
	if (!check_map(env))
		return (false);
	return (pos(env));
}
