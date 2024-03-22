/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:54:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/21 14:30:08 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cube.h"

// typedef struct s_texture_data
// {
// 	int				width;
// 	int				height;
// 	unsigned int	**tex_pixel;
// }	t_tex;

int		render_frame(t_data *data);
void	draw_maps(t_data *d, mlx_image_t *img);
void	draw_square(mlx_image_t *frame, t_pos pos, int size, int color);
void	clear_frame(mlx_image_t *frm, int color);
int		draw_line(mlx_image_t *frame, t_pos start, t_pos end, char **maps, int *hit);
int		draw_verline(mlx_image_t *frame, int x, int y, int to_y, int color);
int		ray_cast(t_data *d, mlx_image_t *frm);
t_tex	*tex_baker(char *tex_file);
#endif