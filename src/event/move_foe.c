/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:32:27 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 17:18:49 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_random(size_t index)
{
	int	seed;
	int	factor;

	return (((size_t)(&seed) / 100 + index) * (size_t)(&factor) / 1000);
}

static void	random_dir(size_t index, size_t *y, size_t *x)
{
	size_t	r;

	r = ft_random(index) % 4;
	if (r == 0)
		*y = *y - 1;
	else if (r == 1)
		*x = *x + 1;
	else if (r == 2)
		*y = *y + 1;
	else
		*x = *x - 1;
}

static void	apply_movement(t_env *env, size_t *total_try, size_t y, size_t x)
{
	size_t	new_y;
	size_t	new_x;
	size_t	try;

	new_y = y;
	new_x = x;
	try = 42;
	while (try && env->map.ptr[new_y][new_x] != EMPTY)
	{
		new_y = y;
		new_x = x;
		random_dir(*total_try, &new_y, &new_x);
		*total_try = *total_try + 1;
		try--;
	}
	if (env->map.ptr[new_y][new_x] != EMPTY)
	{
		env->map.ptr[y][x] = MOVED_FOE;
		return ;
	}
	env->map.ptr[y][x] = EMPTY;
	env->map.ptr[new_y][new_x] = MOVED_FOE;
}

void	move_foe(t_env *env)
{
	size_t	try;
	size_t	y;
	size_t	x;

	try = env->map.pos.move_count;
	y = 1;
	while (y < env->map.h)
	{
		x = 1;
		while (x < env->map.w)
		{
			if (env->map.ptr[y][x] == FOE)
				apply_movement(env, &try, y, x);
			if (env->map.ptr[y - 1][x] == MOVED_FOE)
				env->map.ptr[y - 1][x] = FOE;
			if (env->map.ptr[y][x - 1] == MOVED_FOE)
				env->map.ptr[y][x - 1] = FOE;
			x++;
		}
		y++;
	}
}
