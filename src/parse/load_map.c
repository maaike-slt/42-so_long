/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:19:46 by msloot            #+#    #+#             */
/*   Updated: 2024/04/05 19:07:30 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_line(char *line, size_t len, bool first_or_last)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((first_or_last == true || i == 0) && line[i] != WALL)
			return (ft_puterr("map has to be surrounded by walls\n"), false);
		else if ((first_or_last == true || i == len - 1) && line[i] != WALL)
			return (ft_puterr("map has to be surrounded by walls\n"), false);
		else if ((line[i] != WALL && line[i] != EMPTY && line[i] != PONY)
			&& line[i] != TREASURE && line[i] != EXIT)
			return (ft_puterr(
					"this map is composed with an unvalid character\n"), false);
		i++;
	}
	return (true);
}

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

static size_t	read_map(t_env *env, int fd, size_t	line_count)
{
	char	*line;
	size_t	len;
	bool	first_or_last_line;

	env->map.h = 0;
	first_or_last_line = true;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = empty_line(line);
		if (!len)
			return (0);
		// if (!check_line(line, len, env->map.h == 0 || env->map.h + 1 == line_count - 1))
		if (!check_line(line, len, first_or_last_line))
			return (0);
		if (env->map.h == 0)
			env->map.w = len;
		else if (env->map.w != len)
		{
			free(line);
			return (\
ft_puterr("the given map does not have a rectangular shape\n"), 0);
		}
		env->map.ptr[env->map.h] = line;
		env->map.mapcopy[env->map.h] = ft_strdup(line);
		env->map.h++;
		line = get_next_line(fd);
		if (env->map.h + 1 == line_count)
			first_or_last_line = true;
		else
			first_or_last_line = false;
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
	line_count = read_map(env, fd, line_count);
	close(fd);
	return (line_count);
}
