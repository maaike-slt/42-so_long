/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:48 by msloot            #+#    #+#             */
/*   Updated: 2024/03/25 21:09:03 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	load_sprite_err(const char *path)
{
	ft_puterr("could not load sprite ");
	ft_putstr_fd(Y_B_MAG, STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (false);
}

#include <stdio.h>

static void	apply_transparency(t_img *img)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*buffer;

	buffer = mlx_get_data_addr(img->ptr, &bits_per_pixel, &size_line, &endian);
	printf("pixel: %x\n", *(int *)(buffer));
	for (int y = 0; y < img->h; ++y)
	{
    	for (int x = 0; x < img->w; ++x)
    	{
        	int pixel = (y * size_line) + (x * 4);
        	unsigned int color = *(int *)(buffer + pixel);

        	// Check if the pixel is black
        	if (color == 0xff000000)
        	{
            	// Change to transparent (assuming 0x00000000 for transparent)
            	*(int *)(buffer + pixel) = 0x00FF0000;
        	}
    	}
	}
}

static bool	load_sprite(t_env *env, t_img *img, char *xpm_path)
{
	img->w = 0;
	img->h = 0;
	img->ptr = mlx_xpm_file_to_image(
			env->mlx,
			xpm_path,
			&(img->w),
			&(img->h));
	if (!img->ptr)
		return (load_sprite_err(xpm_path));
	apply_transparency(img);
	printf("%s\nw: %d\nh: %d\n\n", xpm_path, img->w, img->h);
	return (true);
}

bool	load_sprite_lib(t_env *env)
{
	env->spr.wall.ptr = NULL;
	env->spr.floor.ptr = NULL;
	env->spr.exit.ptr = NULL;
	env->spr.pony.ptr = NULL;
	env->spr.treasure.ptr = NULL;
	// put all sprites to NULL
	if (!load_sprite(env, &(env->spr.wall), "./sprite/wall.xpm"))
		return (false);
	if (!load_sprite(env, &(env->spr.floor), "./sprite/floor.xpm"))
		return (false);
	// need to check that all sprite have same width and height as wall
	// beside floor
	if (!load_sprite(env, &(env->spr.exit), "./sprite/exit.xpm"))
		return (false);
	if (!load_sprite(env, &(env->spr.pony), "./sprite/pony.xpm"))
		return (false);
	if (!load_sprite(env, &(env->spr.treasure), "./sprite/treasure.xpm"))
		return (false);
	return (true);
}
