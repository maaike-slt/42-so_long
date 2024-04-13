/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:27:36 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 20:06:25 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_message(t_env *env, char *str, ssize_t won)
{
	close_win(env);
	if (won == -1)
	{
		ft_putstr_fd(Y_B_RED, STDERR_FILENO);
		ft_putstr_fd("lose ", STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
	}
	else if (won == 0)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(Y_B_YLW, STDERR_FILENO);
		ft_putstr_fd(" giving up", STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putstr_fd("??\n", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd(Y_B_GRN, STDERR_FILENO);
		ft_putstr_fd("you won ", STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
	}
}
