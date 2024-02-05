/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:00:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/04 23:47:06 by pruenrua         ###   ########.fr       */
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

typedef struct s_variable
{
	void *mlx;
	void *game_window;
	void *data_window;
	char **maps_data;
}  t_var;

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./control/control.h"
# include "./parser/parser.h"
# include "./render/render.h"
# include "./utill/utill.h"


#endif
