/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:00:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 17:44:09 by pruenrua         ###   ########.fr       */
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
#define SCREEN_HIGHT 800
#define SCREEN_WIDTH 800
#define MINIMAPS_SCALE 20
#define WIN_TITLE "RAYCASTING"

#define W 13
#define A 0
#define S 1
#define D 2
#define LEFT_ARROW 123
#define RIGHT_ARROW 124
#define ESC 53
#define PIXEL_SPEED 2
#define ROTATE_SPEED 1
#define PI 3.14


typedef struct s_positon
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_vector
{
	unsigned int	magnitude;
	t_pos			tail;
	t_pos			head;
	t_pos			unit;
}	t_vector;

typedef struct s_frame_image
{
	void	*image;
	char	*address;
	int		bpp; // bit per pixel
	int		line_length;
	int		endian;
	int		frame_width;
	int		frame_hight;
}	t_frame;

typedef struct s_texture_data
{
	char	**north;
	char	**south;
	char	**west;
	char	**east;
	int		floor[3];
	int		ceil[3];
}	t_texture;

typedef struct s_map_data
{
	char		**maps_array;
	int			maps_width;
	int			maps_hight;
	char		**raw_data;
	t_texture	*texture;
}	t_maps;

typedef struct s_keybind
{
	int		w_key;
	int		a_key;
	int		s_key;
	int		d_key;
	int		left_key;
	int		right_key;
	int		is_keypress;
}	t_key;

typedef	struct s_player_data
{
	t_pos	pos;
	float	angle;
}	t_player ;

typedef struct s_variable
{
	t_player	player;
	void		*mlx;
	void		*game_window;
	void		*data_window;
	t_key		key;
	t_maps		*maps_data;
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
