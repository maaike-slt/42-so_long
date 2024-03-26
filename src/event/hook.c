/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:14 by msloot            #+#    #+#             */
/*   Updated: 2024/03/26 14:41:44 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hook(t_env *env)
{
//	mlx_key_hook(env->win.ptr, move_pony, env);
//	mlx_loop_hook(env->mlx, move_pony, env);
//	mlx_loop(env->mlx);
	mlx_hook(env->win.ptr, ON_DESTROY, NO_EVENT, close_win, env);
}
