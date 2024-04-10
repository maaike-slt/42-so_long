/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/04/10 15:25:15 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	parse(t_env *env, const char *path)
{
	size_t	size;
	ssize_t	line_count;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
		return (ft_puterr
			("not the right filetype, a .ber file is needed\n"), false);
	line_count = count_line(path);
	if (line_count <= 0)
		return (false);
	env->map.ptr = (t_cell **)malloc(sizeof(t_cell *) * (line_count + 1));
	if (!env->map.ptr)
		return (false);
	env->map.mapcopy = (t_cell **)malloc(sizeof(t_cell *) * (line_count + 1));
	if (!env->map.mapcopy)
		return (false);
	if (load_map(env, path) <= 0)
		return (false);
	return (check_map(env));
}
