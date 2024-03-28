/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/03/28 18:20:15 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_pos(t_coord *c, size_t x, size_t y)
{
	c->x = x;
	c->y = y;
}

static bool	pos(t_env *env)
{
	size_t	x;
	size_t	y;
	bool	seen_pony;

	seen_pony = false;
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			if (env->map.ptr[y][x] == EXIT)
				set_pos(&(env->map.pos.exit), x, y);
			else if (env->map.ptr[y][x] == PONY)
			{
				if (seen_pony == true)
					return (ft_puterr("too many ponies in this map, only one allowed\n"));
				set_pos(&(env->map.pos.pony), x, y);
				seen_pony = true;
			}
			x++;
		}
		y++;
	}
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
	if (load_map(env, path) <= 0)
		return (false);
	return (pos(env));
}