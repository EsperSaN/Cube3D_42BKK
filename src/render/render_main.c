/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/27 21:20:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

#define mapWidth 24
#define mapHeight 24

void	put_pixel(t_frame *frame, int x, int y, int color)
{
	char	*adr;

	adr = frame->address;
	adr = frame->address + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int *)adr = color;
}

int	draw_strip(t_frame *frame, int col, int row, int to_row)
{
	int tmp;
	if (row < 0)
		row = 0;
	if (to_row > SCREEN_HIGHT)
		to_row = SCREEN_HIGHT;
	if (row > to_row)
	{
		tmp = to_row;
		to_row = row;
		row = tmp;
	}
	while (++row <= to_row)
		put_pixel(frame, col, row, 0x00FF0000);
}

int render_frame(t_data *data)
{
	t_frame new_frame;
	int x = 0;
	int half = SCREEN_HIGHT / 2;
	new_frame.start_row = 1;
	int vec_size = 100;
	new_frame.end_row = 100;
	new_frame.image = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	new_frame.address = mlx_get_data_addr(new_frame.image, &new_frame.bpp, &new_frame.line_length, &new_frame.endian);

	while (++x < SCREEN_WIDTH)
	{
		new_frame.start_row = (half - (vec_size / 2));
		new_frame.end_row = new_frame.start_row + vec_size;
		printf("draw from %d to %d\n", new_frame.start_row,new_frame.end_row);
		draw_strip(&new_frame, x, new_frame.start_row, new_frame.end_row);
		vec_size += 1;
	}
	//put_pixel(&new_frame, data->posy, data->posx, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->game_window, new_frame.image, 0, 0);
	
	//printf("mlx\nwin = %p\nptr = %p\nimg = %p", data->mlx, data->game_window, new_frame.address);
}