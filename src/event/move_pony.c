/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:25 by msloot            #+#    #+#             */
/*   Updated: 2024/03/27 16:32:47 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move_pony(t_env *env, ssize_t x, ssize_t y)
{
	if (env->map.ptr[env->map.pos.pony.y + y][env->map.pos.pony.x + x] == WALL)
		return ;
	env->map.pos.pony.x += x;
	env->map.pos.pony.y += y;
	printf("%ld\n", x);
	printf("%ld\n", y);
}

bool	movement(int keycode, t_env *env)
{
	if (keycode == K_UP || keycode == K_W)
		return (move_pony(env, 0, -1), true);
	else if (keycode == K_DOWN || keycode == K_S)
		return (move_pony(env, 0, 1), true);
	else if (keycode == K_LEFT || keycode == K_A)
		return (move_pony(env, -1, 0), true);
	else if (keycode == K_RIGHT || keycode == K_D)
		return (move_pony(env, 1, 0), true);
	else
		return (false);
}

int	handle_keycode(int keycode, t_env *env)
{
	// (void)keycode;
	(void)env;
	if (movement(keycode, env))
		return (0);
	else
	{
		ft_putstr("the keycode ");
		ft_putstr(Y_B_MAG);
		ft_putnbr(keycode);
		ft_putstr(Y_RESET);
		ft_putstr(" does not have any effect\n");
	}
	return (0);
}
