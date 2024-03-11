/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/03/11 14:09:00 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	load_map(t_env *env, const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	printf("fd:\t%d\n\n", fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

static bool	init(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
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
	char	*str;
	char	*cut_str;
	size_t	i;
	size_t	n;

	if (argc == 2)
	{
		str = argv[1];
		n = ft_strlen(str) - 1;
		while (str[n] != '\0')
		{
			cut_str[i] = str[n];
			i++;
			n++;
		}
		if (ft_strcmp(cut_str, ".ber") == 0)
		{
			load_map(&env, path);
		}
		else
			ft_puterr("not the right filetype, a .ber file is needed\n");
	}
	else
		ft_puterr("not the right amount of files, 1 file shall be given\n");

	if (!init(&env))
		return (free_env(&env));

	if (!load_sprite_lib(&env))
		return (free_spr(&env) && free_env(&env));

	mlx_pixel_put(env.mlx, env.win, 1920 / 2, 1080 / 2, 0xFFFFFF);

	mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, 0, 0);
	mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, 0, (0 + env.spr.wall.h / 2));
	mlx_put_image_to_window(env.mlx, env.win, env.spr.wall.ptr, (0 + env.spr.wall.w), 0);

	set_hook(&env);

	mlx_loop(env.mlx);

	free_spr(&env);
	free_env(&env);
	return (0);
}
