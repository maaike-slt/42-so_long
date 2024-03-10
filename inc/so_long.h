/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:59:49 by msloot            #+#    #+#             */
/*   Updated: 2024/03/10 15:36:02 by msloot           ###   ########.fr       */
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

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_sprite_lib
{
	t_img	wall;
}	t_sprite_lib;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	t_sprite_lib	spr;
}	t_env;

enum	e_event
{
	ON_DESTROY = 17
};

enum	e_mask
{
	NO_EVENT = 0L
};

void	set_hook(t_env *env);

void	free_env(t_env *env);
int		close_win(t_env *env);

bool	load_sprite_lib(t_env *env);

#endif
