/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/02/29 17:30:51 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
