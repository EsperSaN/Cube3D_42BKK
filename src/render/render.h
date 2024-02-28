/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:54:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 21:51:01 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cube.h"

int 	render_frame(t_data *data);
void	draw_pixel(t_frame *frame, int x, int y, int color);
int		draw_verline(t_frame *frame, int x, int y, int to_y, int color);
int		draw_area(t_frame *frame, int x, int to_x, int y, int to_y, int color);
int 	draw_horline(t_frame *frame, int y, int x, int to_x, int color);
#endif