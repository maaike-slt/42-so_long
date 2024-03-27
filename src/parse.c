/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/03/27 17:12:15 by msloot           ###   ########.fr       */
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
		if (!env->map.ptr)
		{
			if (env->map.h == 0)
				env->map.w = len;
			else if (env->map.w != len)
				return (\
ft_puterr("the given map does not have a rectangular shape\n"), 0);
			free(line);
		}
		else
			env->map.ptr[env->map.h] = line;
		env->map.h++;
		line = get_next_line(fd);
	}
	return (env->map.h);
}

static size_t	load_map(t_env *env, const char *path)
{
	int		fd;
	size_t	n_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_puterr("could not open the file ");
		ft_putstr_fd(Y_B_MAG, STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (0);
	}
	n_line = read_map(env, fd);
	close(fd);
	return (n_line);
}

static void	set_pos(t_coord *c, size_t x, size_t y)
{
	c->x = x;
	c->y = y;
}

static bool	pos(t_env *env)
{
	size_t	x;
	size_t	y;
	bool	seen_pony;

	seen_pony = false;
	y = 0;
	while (y < env->map.h)
	{
		x = 0;
		while (x < env->map.w)
		{
			if (env->map.ptr[y][x] == EXIT)
				set_pos(&(env->map.pos.exit), x, y);
			else if (env->map.ptr[y][x] == PONY)
			{
				if (seen_pony == true)
					return (ft_puterr("too many ponies in this map, only one allowed\n"));
				set_pos(&(env->map.pos.pony), x, y);
				seen_pony = true;
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	parse(t_env *env, const char *path)
{
	size_t	size;
	size_t	n_line;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
	{
		ft_puterr("not the right filetype, a .ber file is needed\n");
		return (false);
	}
	n_line = load_map(env, path);
	if (!n_line)
		return (false);
	env->map.ptr = (t_cell **)malloc(sizeof(t_cell *) * (n_line + 1));
	if (!env->map.ptr)
		return (false);
	if (load_map(env, path) <= 0)
		return (false);
	return (pos(env));
}
