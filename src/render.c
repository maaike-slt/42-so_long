/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/04/05 17:37:52 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	render_floor(t_env *env)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < env->win.h)
	{
		x = 0;
		while (x < env->win.w)
		{
			mlx_put_image_to_window(
				env->mlx, env->win.ptr, env->spr.floor.ptr, x, y);
			x += env->spr.floor.w;
		}
		y += env->spr.floor.h;
	}
}

void	render(t_env *env)
{
	size_t	y;
	size_t	x;

	render_floor(env);
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			if (env->map.ptr[y][x] == WALL)
				mlx_put_image_to_window(
					env->mlx, env->win.ptr, env->spr.wall.ptr,
					env->spr.wall.w * x, env->spr.wall.h * y);
			else if (env->map.ptr[y][x] == EXIT)
			{
				if (env->map.pos.treasure_num == env->map.pos.taken_treasure)
					mlx_put_image_to_window(
						env->mlx, env->win.ptr, env->spr.exit_open.ptr,
						env->spr.wall.w * x, env->spr.wall.h * y);
				else
					mlx_put_image_to_window(
						env->mlx, env->win.ptr, env->spr.exit_closed.ptr,
						env->spr.wall.w * x, env->spr.wall.h * y);
			}
			else if (env->map.ptr[y][x] == PONY)
			{
				if (env->spr.pony_view_right)
					mlx_put_image_to_window(
						env->mlx, env->win.ptr, env->spr.pony_right.ptr,
						env->spr.wall.w * x, env->spr.wall.h * y);
				else
					mlx_put_image_to_window(
						env->mlx, env->win.ptr, env->spr.pony_left.ptr,
						env->spr.wall.w * x, env->spr.wall.h * y);
			}
			else if (env->map.ptr[y][x] == TREASURE)
				mlx_put_image_to_window(
					env->mlx, env->win.ptr, env->spr.treasure.ptr,
					env->spr.wall.w * x, env->spr.wall.h * y);
			x++;
		}
		printf("%s\n", env->map.ptr[y]);
		y++;
	}
	printf("\nw: %zu\n", env->map.w);
	printf("h: %zu\n", env->map.h);
}
