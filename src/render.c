/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/03/20 18:12:45 by msloot           ###   ########.fr       */
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
			x++;
		}
		printf("%s\n", env->map.ptr[y]);
		y++;
	}
	printf("\nw: %zu\n", env->map.w);
	printf("h: %zu\n", env->map.h);
}
