/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:25 by msloot            #+#    #+#             */
/*   Updated: 2024/03/26 14:42:16 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	move_pony(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;

	printf("Hello from key_hook!\n");
	return (0);
}
