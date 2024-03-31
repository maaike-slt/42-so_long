/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:48 by msloot            #+#    #+#             */
/*   Updated: 2024/03/31 01:51:26 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	load_sprite_err(const char *path)
{
	ft_puterr("could not load sprite ");
	ft_putstr_fd(Y_B_MAG, STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (false);
}

#include <stdio.h>

static bool	load_sprite(t_env *env, t_img *img, char *xpm_path)
{
	img->w = 0;
	img->h = 0;
	img->ptr = mlx_xpm_file_to_image(
			env->mlx,
			xpm_path,
			&(img->w),
			&(img->h));
	if (!img->ptr)
		return (load_sprite_err(xpm_path));
	printf("%s\nw: %d\nh: %d\n\n", xpm_path, img->w, img->h);
	return (true);
}

bool	load_sprite_lib(t_env *env)
{
	env->spr.wall.ptr = NULL;
	env->spr.floor.ptr = NULL;
	env->spr.exit_closed.ptr = NULL;
	env->spr.exit_open.ptr = NULL;
	env->spr.pony.ptr = NULL;
	env->spr.treasure.ptr = NULL;
	// put all sprites to NULL
	if (!load_sprite(env, &(env->spr.wall), "./sprite/wall.xpm"))
		return (false);
	if (!load_sprite(env, &(env->spr.floor), "./sprite/floor.xpm"))
		return (false);
	// need to check that all sprite have same width and height as wall
	// beside floor
	if (!load_sprite(env, &(env->spr.exit_closed), "./sprite/exit_closed.xpm"))
		return (false);
	if (!load_sprite(env, &(env->spr.exit_open), "./sprite/exit_open.xpm"))
		return (false);
	if (env->spr.exit_closed.w != env->spr.wall.w || env->spr.exit_closed.h != env->spr.wall.h)
		return (ft_puterr("the exit must have the same size as the wall"), false);
	if (!load_sprite(env, &(env->spr.pony), "./sprite/pony.xpm"))
		return (false);
	if (env->spr.pony.w != env->spr.wall.w || env->spr.pony.h != env->spr.wall.h)
		return (ft_puterr("the pony must have the same size as the wall"), false);
	if (!load_sprite(env, &(env->spr.treasure), "./sprite/treasure.xpm"))
		return (false);
	if (env->spr.treasure.w != env->spr.wall.w || env->spr.treasure.h != env->spr.wall.h)
		return (ft_puterr("the treasure must have the same size as the wall"), false);
	return (true);
}
