/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:56:06 by msloot            #+#    #+#             */
/*   Updated: 2024/03/06 19:02:08 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_env(t_env *env)
{
	if (env->mlx && env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
		free(env->mlx);
}
