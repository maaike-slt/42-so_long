/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:48 by msloot            #+#    #+#             */
/*   Updated: 2024/03/12 17:57:20 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return (false);
	return (true);
}

bool	load_sprite_lib(t_env *env)
{
	env->spr.wall.ptr = NULL;
	// put all sprites to NULL
	if (!load_sprite(env, &(env->spr.wall), "./sprite/wall.xpm"))
		return (false);
	return (true);
}
