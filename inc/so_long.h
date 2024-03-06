/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:59:49 by msloot            #+#    #+#             */
/*   Updated: 2024/03/06 19:36:38 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"

# ifndef WINDOW_NAME
#  define WINDOW_NAME	"so_my little pony"
# endif

typedef struct s_env
{
	void	*mlx;
	void	*win;
}	t_env;

void	free_env(t_env *env);
int		close_win(t_env *env);

#endif
