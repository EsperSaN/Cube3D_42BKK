/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:54:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 16:23:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cube.h"

int 	render_frame(t_data *data);
int		draw_vertex(t_frame *frame, t_pos start, t_pos end, char **maps);
void	draw_pixel(t_frame *frame, int x, int y, int color);
int		draw_verline(t_frame *frame, int x, int y, int to_y, int color);
int		draw_maps(t_data *d, t_frame *img);
int 	draw_square(t_frame *frame, t_pos pos, int size);
int		draw_area(t_frame *frame, int x, int to_x, int y, int to_y, int color);
int 	draw_horline(t_frame *frame, int y, int x, int to_x, int color);
#endif