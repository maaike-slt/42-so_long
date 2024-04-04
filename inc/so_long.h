/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:59:49 by msloot            #+#    #+#             */
/*   Updated: 2024/04/04 21:08:43 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WITH_OPEN

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
	t_img	floor;
	t_img	wall;
	t_img	exit_closed;
	t_img	exit_open;
	t_img	pony_left;
	t_img	pony_right;
	bool	pony_view_right;
	t_img	treasure;
}	t_sprite_lib;

typedef struct s_win
{
	void	*ptr;
	size_t	w;
	size_t	h;
}	t_win;

typedef char		t_cell;

typedef struct s_coord
{
	size_t	x;
	size_t	y;
}	t_coord;


typedef struct s_pos
{
	t_coord	pony;
	t_coord	exit;
	size_t	treasure_num;
	size_t	taken_treasure;
}	t_pos;


typedef struct s_map
{
	t_cell	**ptr;
	t_cell	**mapcopy;
	size_t	w;
	size_t	h;
	t_pos	pos;
}	t_map;

typedef struct s_env
{
	void			*mlx;
	t_win			win;
	t_map			map;
	t_sprite_lib	spr;
}	t_env;

enum	e_cell
{
	EMPTY = '0',
	WALL = '1',
	PONY = 'P',
	EXIT = 'E',
	TREASURE = 'C'
};

enum	e_event
{
	KEY_PRESS = 2,
	ON_DESTROY = 17
};

enum	e_mask
{
	NO_EVENT = 0L
};

enum	e_keypress_linux
{
	K_ESC = 65307,
	K_Z = 122,
	K_Q = 113,
	K_LEFT = 65361,
	K_UP = 65362,
	K_RIGHT = 65363,
	K_DOWN = 65364,
	K_W = 119,
	K_A = 97,
	K_S = 115,
	K_D = 100,
};

void	set_hook(t_env *env);

int		free_env(t_env *env);
int		free_spr(t_env *env);
int		close_win(t_env *env);
int		handle_keycode(int keycode, t_env *env);

bool	load_sprite_lib(t_env *env);
bool	create_window(t_env *env);

bool	parse(t_env *env, const char *path);
void	render(t_env *env);
size_t	load_map(t_env *env, const char *path);

#endif
