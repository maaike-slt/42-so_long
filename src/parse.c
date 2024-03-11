/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/03/11 17:56:48 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	parse(t_env *env, const char *path)
{
	size_t	size;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
	{
		ft_puterr("not the right filetype, a .ber file is needed\n");
		return (false);
	}
	load_map(&env, path);
	return (true);
}
