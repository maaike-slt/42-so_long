/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:48 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 15:58:26 by msloot           ###   ########.fr       */
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
	return (true);
}

bool	load_sprite_lib(t_env *env)
{
	env->spr.wall.ptr = NULL;
	env->spr.floor.ptr = NULL;
	env->spr.exit_closed.ptr = NULL;
	env->spr.exit_open.ptr = NULL;
	env->spr.pony_left.ptr = NULL;
	env->spr.pony_right.ptr = NULL;
	env->spr.pony_view_right = true;
	env->spr.treasure.ptr = NULL;
	env->spr.foe.ptr = NULL;
	return (load_sprite(env, &(env->spr.wall), "./sprite/wall.xpm")
		&& load_sprite(env, &(env->spr.floor), "./sprite/floor.xpm")
		&& load_sprite(env, &(env->spr.exit_closed), "./sprite/exit_closed.xpm")
		&& load_sprite(env, &(env->spr.exit_open), "./sprite/exit_open.xpm")
		&& load_sprite(env, &(env->spr.pony_left), "./sprite/pony_left.xpm")
		&& load_sprite(env, &(env->spr.pony_right), "./sprite/pony_right.xpm")
		&& load_sprite(env, &(env->spr.treasure), "./sprite/treasure.xpm")
		&& load_sprite(env, &(env->spr.foe), "./sprite/changeling.xpm"));
}
