/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:00:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 20:28:45 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>

# ifdef __APPLE__
# include "../minilibx/mlx-mac/mlx.h"
# else
# include "../minilibx/mlx-linux/mlx.h"
#endif
#define INVALID_ARG "No argument supplied"
#define FAIL 0
#define SCREEN_HIGHT 720
#define SCREEN_WIDTH 1280
#define WIN_TITLE "RAYCASTING"

#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define PIXEL_SPEED 5

typedef struct s_frame_image
{
	void *image;
	char *address;
	int bpp; // bit per pixel
	int line_length;
	int endian;
	int end_row;
	int start_row;
}	t_frame;

typedef struct s_texture_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor[3];
	int		ceil[3];
}	t_texture;

typedef struct s_map_data
{
	char		**maps_array;
	t_texture	*texture;
}	t_maps;

typedef struct s_variable
{
	int		posx;
	int		posy;
	void	*mlx;
	void	*game_window;
	void	*data_window;
	char	**raw_data;
	int		w_key;
	int		a_key;
	int		s_key;
	int		d_key;
	t_maps	*maps_data;
}	t_data;

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "./control/control.h"
# include "./parser/parser.h"
# include "./render/render.h"
# include "./utill/utill.h"



#endif
