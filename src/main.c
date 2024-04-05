/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/04/05 14:44:57 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win.ptr = NULL;
	env->map.mapcopy = NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	if (argc != 2)
		return (ft_puterr(
				"not the right amount of files, 1 file shall be given\n"), 1);
	if (!init(&env))
		return (free_env(&env));
	if (!parse(&env, argv[1]))
		return (free_env(&env));
	if (!load_sprite_lib(&env))
		return (free_spr(&env) && free_env(&env));
	if (!create_window(&env))
		return (free_spr(&env) && free_env(&env));
	set_hook(&env);
	render(&env);

	mlx_loop(env.mlx);

	free_spr(&env);
	free_env(&env);
	return (0);
}
