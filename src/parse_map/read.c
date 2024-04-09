/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:09:09 by msloot            #+#    #+#             */
/*   Updated: 2024/04/09 19:32:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	empty_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (!len || line[0] == '\n')
		return (ft_puterr("found an empty line while reading the map"), 0);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	return (len);
}

static size_t	read_map(t_env *env, int fd)
{
	char	*line;
	size_t	len;

	env->map.h = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = empty_line(line);
		if (!len)
			return (0);
		if (env->map.h == 0)
			env->map.w = len;
		env->map.ptr[env->map.h] = line;
		env->map.mapcopy[env->map.h] = ft_strdup(line);
		env->map.h++;
		line = get_next_line(fd);
	}
	return (env->map.h);
}

size_t	load_map(t_env *env, const char *path)
{
	int		fd;
	ssize_t	line_count;

	line_count = count_line(path);
	if (line_count <= 0)
		return (0);
	fd = open(path, O_RDONLY);
	line_count = read_map(env, fd);
	close(fd);
	return (line_count);
}
