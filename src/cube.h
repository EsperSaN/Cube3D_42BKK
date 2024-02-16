/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:00:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/15 17:32:50 by pruenrua         ###   ########.fr       */
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
	void	*mlx;
	void	*game_window;
	void	*data_window;
	char	**raw_data;
	t_maps	*maps_data;
}	t_var;

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./control/control.h"
# include "./parser/parser.h"
# include "./render/render.h"
# include "./utill/utill.h"


#endif
