/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 19:16:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			mlx_put_image_to_window(env->mlx, env->win.ptr, env->spr.floor.ptr,
				x, y);
			x += env->spr.floor.w;
		}
		y += env->spr.floor.h;
	}
}

static void	put_sprite(t_env *env, void *ptr, size_t y, size_t x)
{
	mlx_put_image_to_window(env->mlx, env->win.ptr, ptr, env->spr.wall.w * x,
		env->spr.wall.h * y);
}

static void	render_treasure(t_env *env, size_t y, size_t x, size_t i)
{
	if (i % 4 == 0)
		put_sprite(env, env->spr.treasure_down.ptr, y, x);
	else if (i % 4 == 1 || i % 4 == 3)
		put_sprite(env, env->spr.treasure_middle.ptr, y, x);
	else if (i % 4 == 2)
		put_sprite(env, env->spr.treasure_up.ptr, y, x);
}

static void	render_cell(t_env *env, size_t y, size_t x, size_t i)
{
	if (env->map.ptr[y][x] == WALL)
		put_sprite(env, env->spr.wall.ptr, y, x);
	else if (env->map.ptr[y][x] == EXIT)
	{
		if (env->map.pos.treasure_num == env->map.pos.taken_treasure)
			put_sprite(env, env->spr.exit_open.ptr, y, x);
		else
			put_sprite(env, env->spr.exit_closed.ptr, y, x);
	}
	else if (env->map.ptr[y][x] == PONY)
	{
		if (env->spr.pony_view_right)
			put_sprite(env, env->spr.pony_right.ptr, y, x);
		else
			put_sprite(env, env->spr.pony_left.ptr, y, x);
	}
	else if (env->map.ptr[y][x] == TREASURE)
		render_treasure(env, y, x, i);
	else if (env->map.ptr[y][x] == FOE)
		put_sprite(env, env->spr.foe.ptr, y, x);
}

void	render(t_env *env)
{
	size_t	y;
	size_t	x;
	char	buffer[16];

	render_floor(env);
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			render_cell(env, y, x, env->map.pos.move_treasure);
			x++;
		}
		y++;
	}
	ft_unbr_convert
		(buffer, env->map.pos.move_count, ft_nbrlen(env->map.pos.move_count));
	mlx_string_put(env->mlx, env->win.ptr,
		env->map.w * env->spr.wall.w - env->spr.wall.w / 2 - 3,
		env->spr.wall.h / 2 + 5, 0xfff99b, buffer);
	env->map.pos.move_treasure++;
}
