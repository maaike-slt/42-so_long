/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:21 by msloot            #+#    #+#             */
/*   Updated: 2024/03/20 15:36:57 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	create_window(t_env *env)
{
	size_t	win_w;
	size_t	win_h;

	win_w = env->map.w * env->spr.wall.w;
	win_h = env->map.h * env->spr.wall.h;
	env->win = mlx_new_window(env->mlx, win_w, win_h, WINDOW_NAME);
	if (!env->win)
		return (false);
	return (true);
}
