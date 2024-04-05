/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:56:06 by msloot            #+#    #+#             */
/*   Updated: 2024/04/05 17:59:05 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_env(t_env *env)
{
	if (env->map.ptr)
		ft_free_2d((void ***)&(env->map.ptr), env->map.h);
	if (env->map.mapcopy)
		ft_free_2d((void ***)&(env->map.mapcopy), env->map.h);
	if (env->mlx && env->win.ptr)
		mlx_destroy_window(env->mlx, env->win.ptr);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	return (1);
}

int	free_spr(t_env *env)
{
	if (env->spr.wall.ptr)
		mlx_destroy_image(env->mlx, env->spr.wall.ptr);
	if (env->spr.floor.ptr)
		mlx_destroy_image(env->mlx, env->spr.floor.ptr);
	if (env->spr.exit_closed.ptr)
		mlx_destroy_image(env->mlx, env->spr.exit_closed.ptr);
	if (env->spr.exit_open.ptr)
		mlx_destroy_image(env->mlx, env->spr.exit_open.ptr);
	if (env->spr.pony_left.ptr)
		mlx_destroy_image(env->mlx, env->spr.pony_left.ptr);
	if (env->spr.pony_right.ptr)
		mlx_destroy_image(env->mlx, env->spr.pony_right.ptr);
	if (env->spr.treasure.ptr)
		mlx_destroy_image(env->mlx, env->spr.treasure.ptr);
	return (1);
}
