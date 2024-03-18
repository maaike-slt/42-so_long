/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/03/18 18:09:16 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	render(t_env *env)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			if (env->map.ptr[y][x] == WALL)
				mlx_put_image_to_window(
					env->mlx, env->win, env->spr.wall.ptr,
					(0 + env->spr.wall.w * x), (0 + env->spr.wall.h * y));
			x++;
		}
		printf("%s\n", env->map.ptr[y]);
		y++;
	}
	printf("\nw: %zu\n", env->map.w);
	printf("h: %zu\n", env->map.h);
}
