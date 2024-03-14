/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/03/14 17:31:30 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->map.ptr = NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	env->win = mlx_new_window(env->mlx, 1920, 1080, WINDOW_NAME);
	if (!env->win)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	size_t	i;

	if (argc != 2)
		return (ft_puterr(
				"not the right amount of files, 1 file shall be given\n"), 1);
	if (!init(&env))
		return (free_env(&env));
	if (!parse(&env, argv[1]))
		return (free_env(&env));
	if (!load_sprite_lib(&env))
		return (free_spr(&env) && free_env(&env));

	mlx_pixel_put(env.mlx, env.win, 1920 / 2, 1080 / 2, 0xFFFFFF);

	mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, 0, 0);
	mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, 0, (0 + env.spr.wall.h / 2));
	i = 1;
	while (env.spr.wall.w * i <= 1920)
	{
		mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, (0 + env.spr.wall.w * i), 0);
		i++;
	}

	set_hook(&env);

	mlx_loop(env.mlx);

	free_spr(&env);
	free_env(&env);
	return (0);
}
