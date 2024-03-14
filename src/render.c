/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/03/14 17:28:26 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

size_t	render(t_env *env, int fd, size_t n_line)
{
	char	*line;

	line = get_next_line(fd);
	env->map.w = ft_strlen(&line[n_line]);
	while (line != NULL)
	{
		if (env->map.ptr)
			env->map.ptr[n_line] = line;
		n_line++;
		printf("%s", line);
		if (ft_strlen(line) != env->map.w)
		{
			ft_puterr("the given map does not have a rectangular shape\n");
			return (-1);
		}
		if (!env->map.ptr)
			free(line);
		line = get_next_line(fd);
	}
	env->map.h = n_line;
	printf("\n%zu\n", env->map.w - 1);
	printf("%zu\n", env->map.h);
	return (n_line);
}
