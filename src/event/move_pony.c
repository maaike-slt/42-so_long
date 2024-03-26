/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:25 by msloot            #+#    #+#             */
/*   Updated: 2024/03/26 21:20:53 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

bool	movement(int keycode, t_env *env)
{
	if (keycode == K_UP || keycode == K_W)
		return (move_pony(env, 0, -1));
	else if (keycode == K_DOWN || keycode == K_S)
		printf("key: %d\tdown\n", keycode);
	else if (keycode == K_LEFT || keycode == K_A)
		printf("key: %d\tleft\n", keycode);
	else if (keycode == K_RIGHT || keycode == K_D)
		printf("key: %d\tright\n", keycode);
	else
		return (false);
}

bool	move_pony(t_env *env, ssize_t x, ssize_t y)
{
//	env.
	printf("%s\n", "key: up");
	return (true);
}
