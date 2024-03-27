/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:25 by msloot            #+#    #+#             */
/*   Updated: 2024/03/27 13:21:42 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

bool	move_pony(t_env *env, ssize_t x, ssize_t y)
{
	(void)x;
	(void)y;
	(void)env;
	// env->map.pos.pony.x 
	printf("%ld\n", x);
	printf("%ld\n", y);
	return (true);
}

bool	movement(int keycode, t_env *env)
{
	if (keycode == K_UP || keycode == K_W)
		return (move_pony(env, 0, -1));
	else if (keycode == K_DOWN || keycode == K_S)
		return (move_pony(env, 0, 1));
	else if (keycode == K_LEFT || keycode == K_A)
		return (move_pony(env, -1, 0));
	else if (keycode == K_RIGHT || keycode == K_D)
		return (move_pony(env, 1, 0));
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
