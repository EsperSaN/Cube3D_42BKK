/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:00:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 21:17:46 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../lib/MLX42_codam/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"


# define SUCCESS 1
# define TRUE 1
# define FALSE 0
# define FAIL 0
# define PI 3.14123456789098765432123456789876543212345678909876543f // it will cut to 6 digit by float

typedef struct s_positon
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_position_int
{
	int		x;
	int		y;
}	t_pos_int;

typedef struct s_vector
{
	float			magnitude;
	t_pos			tail;
	t_pos			head;
	t_pos			unit;
}	t_vector;


typedef struct s_texture_data
{
	char	**north;
	char	**south;
	char	**west;
	char	**east;
	int		floor[3];
	int		ceil[3];
}	t_texture;

typedef struct s_pair
{
	int		x;
	int		y;
}	t_pair;

typedef struct s_map_data
{
	char		**maps_array;
	char		**raw_data;
	int			maps_height;
	int			maps_width;
	int			fl_status;
	t_texture	*texture;
	t_pair		player_pos;
}	t_maps;


typedef struct s_player_data
{
	t_pos	pos;
	t_pos	dir;
	t_pos	pane;
	// t_pos	camera;
	float	fov;
	float	angle;
}	t_player;

typedef struct s_ray_data
{
	t_pos		camera;
	t_pos 		ray_dir;
	t_pos		side_distant;
	t_pos		delta_distant;
	t_pos_int 	step;
	t_pos_int 	pos;
	int			color;
	float		perp_wall_distant;
	int			is_hit;
	int			hit_side;
	int			line_s;
	int			line_e;
	int			line_hight;
}	t_raydata;

typedef struct s_variable
{
	t_player	player;
	mlx_t		*mlx;
	mlx_image_t	*map_frm;
	mlx_image_t	*game_frm;
	t_maps		*maps_data;
}	t_data;

# include "./setting.h"
# include "./control/control.h"
# include "./parser/parser.h"
# include "./render/render.h"
# include "./utill/utill.h"




#endif
