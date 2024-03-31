/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:25 by msloot            #+#    #+#             */
/*   Updated: 2024/03/31 03:23:53 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pony(t_env *env, ssize_t x, ssize_t y)
{
	size_t	new_y;
	size_t	new_x;

	new_y = env->map.pos.pony.y + y;
	new_x = env->map.pos.pony.x + x;
	if (env->map.ptr[new_y][new_x] == WALL ||
			(env->map.ptr[new_y][new_x] == EXIT &&
			env->map.pos.taken_treasure < env->map.pos.treasure_num))
		return ;
	else if (env->map.ptr[new_y][new_x] == EXIT)
		close_win(env);
	else if (env->map.ptr[new_y][new_x] == TREASURE)
		env->map.pos.taken_treasure++;
	env->map.ptr[env->map.pos.pony.y][env->map.pos.pony.x] = EMPTY;
	env->map.ptr[new_y][new_x] = PONY;
	env->map.pos.pony.y = new_y;
	env->map.pos.pony.x = new_x;
	if (x > 0)
		env->spr.pony_view_right = true;
	else if (x < 0)
		env->spr.pony_view_right = false;
	render(env);
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

bool	closing_key(int keycode, t_env *env)
{
	if (keycode == K_Q || keycode == K_ESC)
		return (close_win(env), true);
	return (false);
}

int	handle_keycode(int keycode, t_env *env)
{
	// (void)keycode;
	(void)env;
	if (movement(keycode, env))
		return (0);
	if (closing_key(keycode, env))
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
