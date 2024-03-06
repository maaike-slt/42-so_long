/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/03/05 20:39:20 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	size_t	i;
	size_t	n;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	n = 0;
	while (n <= 1080)
	{
		i = 0;
		while (i <= 1920)
		{
			mlx_pixel_put(mlx, mlx_win, i, n, 0xff0000);
			i++;
		}
		n++;
	}
	mlx_pixel_put(mlx, mlx_win, 1920 / 2, 1080 / 2, 0xFFFFFF);

	mlx_loop(mlx);

	mlx_destroy_window(mlx, mlx_win);

	free(mlx);
}
