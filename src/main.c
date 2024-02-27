/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2024/02/26 20:20:11 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		if (ft_strncmp(argv[1], ".ber", ft_strlen(argv[1])) == 0)
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
			write(1, "Not the right filetype", 22);
	}
	else
		write(1, "Not the right amount of files", 29);
	return (0);
}
