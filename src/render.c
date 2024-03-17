/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:38:52 by msloot            #+#    #+#             */
/*   Updated: 2024/03/17 19:08:39 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	render(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->map.h)
	{
		printf("%s\n", env->map.ptr[i]);
		i++;
	}
	printf("\nw: %zu\n", env->map.w);
	printf("h: %zu\n", env->map.h);
}
