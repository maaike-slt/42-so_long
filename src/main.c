/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/03/10 14:41:54 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		if (ft_strcmp(ft_strcut(argv[1]), ".ber") == 0)
		{
			fd = open(argv[1], O_RDONLY);
			printf("fd:\t%d\n\n", fd);
			line = get_next_line(fd);
			while (line != NULL)
			{
				printf("%s", line);
				free(line);
				line = get_next_line(fd);
			}
			close(fd);
		}
		else
			write(1, "Not the right filetype, a .ber file is needed.", 46);
	}
	else
		write(1, "Not the right amount of files, 1 file shall be given", 53);
	return (0);
}
*/

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

#include <stdio.h>

int	main(void)
{
	t_env	env;
	size_t	i;
	size_t	n;

	if (!init(&env))
	{
		free_env(&env);
		return (1);
	}

	printf("%d\n%d\n%p", img_width, img_height, img);


	n = 0;
	i = 0;
	while (n <= 1080)
	{
		while (i <= 1920)
		{
			mlx_pixel_put(env.mlx, env.win, i, n, 0xff0000);
			i++;
		}
		n++;
	}
	mlx_pixel_put(env.mlx, env.win, 1920 / 2, 1080 / 2, 0xFFFFFF);

	mlx_put_image_to_window(env.mlx, env.win, img, 42, 42);

	set_hook(&env);

	mlx_loop(env.mlx);

	mlx_destroy_image(env.mlx, img);

	free_env(&env);
}
