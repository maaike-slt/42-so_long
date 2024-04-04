/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:21 by msloot            #+#    #+#             */
/*   Updated: 2024/04/04 17:50:50 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	create_window(t_env *env)
{
	env->win.w = env->map.w * env->spr.wall.w;
	env->win.h = env->map.h * env->spr.wall.h;
	env->win.ptr = mlx_new_window(
			env->mlx, env->win.w, env->win.h, WINDOW_NAME);
	if (!env->win.ptr)
		return (false);
	return (true);
}
