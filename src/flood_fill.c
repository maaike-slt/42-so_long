/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:37:45 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 20:14:30 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_env *env, size_t move_y, size_t move_x)
{
	if (env->map.mapcopy[move_y][move_x] == EXIT)
		env->map.mapcopy[move_y][move_x] = WALL;
	if (env->map.mapcopy[move_y][move_x] == WALL)
		return ;
	env->map.mapcopy[move_y][move_x] = WALL;
	flood_fill(env, move_y - 1, move_x);
	flood_fill(env, move_y + 1, move_x);
	flood_fill(env, move_y, move_x - 1);
	flood_fill(env, move_y, move_x + 1);
}

bool	all_reachable(t_env *env)
{
	size_t	y;
	size_t	x;

	flood_fill(env, env->map.pos.pony.y, env->map.pos.pony.x);
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			if (env->map.mapcopy[y][x] == TREASURE)
				return (ft_puterr
					("one or more treasures are not reachable\n"), false);
			if (env->map.mapcopy[y][x] == EXIT)
				return (ft_puterr("the exit is not reachable\n"), false);
			x++;
		}
		y++;
	}
	return (true);
}
