/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:48 by msloot            #+#    #+#             */
/*   Updated: 2024/03/10 14:42:10 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	load_sprite_lib(t_env *env)
{
}

bool	load_sprite(t_env *env, t_img *img, const char *xpm_path)
{
	img->w = 0;
	img->h = 0;
	img = mlx_xpm_file_to_image(env->mlx, xpm_path, &(img->w), &(img->h));
	if (!img)
		return (false);
	return (true);
}
