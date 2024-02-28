/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 21:51:15 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

int player_pos(t_data *data)
{
	if (data->w_key == 1)
		data->posy -= PIXEL_SPEED;
	if (data->s_key == 1)
		data->posy += PIXEL_SPEED;
	if (data->a_key == 1)
		data->posx -= PIXEL_SPEED;
	if (data->d_key == 1)
		data->posx += PIXEL_SPEED;
}

int render_frame(t_data *data)
{
	t_frame frame;
	int x = 0;
	int half = SCREEN_HIGHT / 2;
	player_pos(data);
	frame.start_row = 1;
	int vec_size = 100;
	frame.end_row = 100;
	frame.image = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	frame.address = mlx_get_data_addr(frame.image, &frame.bpp, &frame.line_length, &frame.endian);
	draw_verline(&frame, data->posx , 0 , SCREEN_HIGHT,0x00FF0000);
	draw_horline(&frame, data->posy, 0 , SCREEN_WIDTH, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->game_window, frame.image, 0, 0);
	mlx_destroy_image(data->mlx, frame.image);
}