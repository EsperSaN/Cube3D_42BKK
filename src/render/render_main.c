/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 18:30:56 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"


int	position_adjust(t_data *data)
{
	if (data->key.w_key == PRESS)
	{
		data->player.pos.y -= PIXEL_SPEED;
		int x = (data->player.pos.x) / MINIMAPS_SCALE;
		int y =	(data->player.pos.y) / MINIMAPS_SCALE;
		if (data->maps_data->maps_array[y][x] != '0')
			data->player.pos.y += PIXEL_SPEED;
	}
	if (data->key.s_key == PRESS)
	{
		data->player.pos.y += PIXEL_SPEED;
		int x = (data->player.pos.x) / MINIMAPS_SCALE;
		int y =	(data->player.pos.y) / MINIMAPS_SCALE;
		if (data->maps_data->maps_array[y][x] != '0')
			data->player.pos.y -= PIXEL_SPEED;
	}
	if (data->key.a_key == PRESS)
	{
		data->player.pos.x -= PIXEL_SPEED;
		int x = (data->player.pos.x) / MINIMAPS_SCALE;
		int y =	(data->player.pos.y) / MINIMAPS_SCALE;
		if (data->maps_data->maps_array[y][x] != '0')
			data->player.pos.x += PIXEL_SPEED;
	}
	if (data->key.d_key == PRESS)
	{
		data->player.pos.x += PIXEL_SPEED;
		int x = (data->player.pos.x) / MINIMAPS_SCALE;
		int y =	(data->player.pos.y) / MINIMAPS_SCALE;
		if (data->maps_data->maps_array[y][x] != '0')
			data->player.pos.x -= PIXEL_SPEED;
	}

	if (data->player.pos.x > SCREEN_WIDTH)
		data->player.pos.x = SCREEN_WIDTH - 1;
	if (data->player.pos.y > SCREEN_HIGHT)
		data->player.pos.y = SCREEN_HIGHT - 1;

	if (data->key.left_key == PRESS)
		data->player.angle -= ROTATE_SPEED;
	if (data->key.right_key == PRESS)
		data->player.angle += ROTATE_SPEED;
	if (data->player.pos.x < 0)
		data->player.pos.x = 0;
	if (data->player.pos.y < 0)
		data->player.pos.y = 0;
}

int	put_img_to_window(void *mlx, void *window, t_frame *frm)
{
	mlx_put_image_to_window(mlx, window, frm->image, 0, 0);
}

int	destory_image(t_data *d, t_frame *frm)
{
	mlx_destroy_image(d->mlx, frm->image);
}

t_frame	new_image(void *mlx, int width, int hight)
{
	t_frame	frm;

	printf("crate img with %d x %d\n", width, hight);
	frm.image = mlx_new_image(mlx, width, hight);
	frm.address = mlx_get_data_addr(frm.image, &frm.bpp, \
						&frm.line_length, &frm.endian);
	frm.frame_hight = hight;
	frm.frame_width = width;
	return (frm);
}

int	is_keypress(t_key key)
{
	if (key.a_key == PRESS)
		return (1);
	if (key.w_key == PRESS)
		return (1);
	if (key.s_key == PRESS)
		return (1);
	if (key.d_key == PRESS)
		return (1);
	if (key.left_key == PRESS)
		return (1);
	if (key.right_key == PRESS)
		return (1);
	return (0);

}
int draw_player(t_frame *frame, t_pos pos, int color)
{
	pos.x -= 2;
	pos.y -= 2;
	draw_square(frame, pos, 5);
}

int	render_frame(t_data *data)
{
	t_frame	game_img;
	t_frame	data_img;
	t_pos	start;
	t_pos	end;

	if (is_keypress(data->key)) // should change to any key press function
	{start.x = data->player.pos.x;
	start.y = data->player.pos.y;
	end.x = (start.x+200 * cosf(data->player.angle *(PI/180)));
	end.y = (start.y+200 * sinf(data->player.angle *(PI/180)));
	position_adjust(data);
	game_img = new_image(data->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	printf("crate game with %d x %d\n", game_img.frame_hight, game_img.frame_width);
	data_img = new_image(data->mlx, data->maps_data->maps_width * MINIMAPS_SCALE, data->maps_data->maps_hight * MINIMAPS_SCALE);
	float a = -45;
	int x = 0;
	while (a < 45)
	{	
		t_pos ray;
		ray.x = (start.x + 200 * cosf((data->player.angle + a) *(PI/180)));
		ray.y = (start.y + 200 * sinf((data->player.angle + a) *(PI/180)));
		int size = draw_vertex(&data_img, start, ray,data->maps_data->maps_array);
		a+=0.1;
		size -= 75 + (75 * cosf((data->player.angle + a) *(PI/180)));
		int in_size = abs(400 - size);
		if (in_size < 0)
			in_size = 0;
		if (in_size < 200 - 1)
			draw_verline(&game_img, x, (game_img.frame_hight / 2) - (in_size / 2), (in_size * 2 * atan(0.66/1.0)) , 0x00FF0000);
		printf("x = %d angle = %.2f vec_size = %d \n", x, a, size);
		x += 1;
	}
	draw_player(&data_img, data->player.pos, 0x00FF0000);
	draw_maps(data, &data_img);
	put_img_to_window(data->mlx, data->data_window, &data_img);
	put_img_to_window(data->mlx, data->game_window, &game_img);
	destory_image(data, &data_img);
	destory_image(data, &game_img);}
}
