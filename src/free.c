/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:56:06 by msloot            #+#    #+#             */
/*   Updated: 2024/03/17 19:09:46 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_env(t_env *env)
{
	if (env->map.ptr)
		ft_free_2d((void ***)&(env->map.ptr), env->map.h);
	if (env->mlx && env->win)
		mlx_destroy_window(env->mlx, env->win);
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
	return (1);
}
