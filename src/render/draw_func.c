/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:58:27 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 17:24:18 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

int	draw_maps(t_data *d, t_frame *img)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	while (i < d->maps_data->maps_width)
	{
		pos.y = 0;
		j = 0;
		while (j < d->maps_data->maps_width)
		{
			if (d->maps_data->maps_array[j][i] != '0')
				draw_square(img, pos, MINIMAPS_SCALE - 1);
			pos.y += 20;
			j++;
		}
		pos.x += 20;
		i++;
	}
	return (d);
}

void	draw_pixel(t_frame *frame, int x, int y, int color)
{
	char	*adr;

	if (x < 0 || y < 0 || x >= frame->frame_width || y >= frame->frame_hight)
		return ;
	adr = frame->address;
	adr = frame->address + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int *)adr = color;
}

int	draw_verline(t_frame *frame, int x, int y, int to_y, int color)
{
	int	tmp;

	// if (y > to_y || y < 0)
	// 	return 0;
	if (y > to_y)
	{
		tmp = to_y;
		to_y = y;
		y = tmp;
	}
	if (y < 0)
		y = 0;
	if (to_y > frame->frame_hight)
		to_y = frame->frame_hight;
	
	while (++y <= to_y)
		draw_pixel(frame, x, y, color);
}

int draw_horline(t_frame *frame, int y, int x, int to_x, int color)
{
	int	tmp;

	if (x > to_x)
	{
		tmp = to_x;
		to_x = x;
		x = tmp;
	}
	if (y < 0)
		y = 0;
	if (to_x > SCREEN_WIDTH)
		to_x = SCREEN_WIDTH;

	while (++x <= to_x)
		draw_pixel(frame, x, y, color);
}

// y = mx+b
int	draw_vertex(t_frame *frame, t_pos start, t_pos end, char **maps)
{
	float	step;
	float	delta_x;
	float	delta_y;
	float	x_step;
	float	y_step;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	//printf("DDA dx = %.2f dy = %.fy\n", delta_x,delta_y);
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	x_step = delta_x / step;
	y_step = delta_y / step;
	//printf("x_step = %.2f y_step = %.2f\n", x_step, y_step);
	int tmp = step;
	while (step > 0)
	{
		if (maps[(int)start.y / MINIMAPS_SCALE][(int)start.x/MINIMAPS_SCALE] != '0')
			break;
		draw_pixel(frame, (int)start.x, (int)start.y,  0x00FF0000);
		start.x = start.x + x_step;
		start.y = start.y + y_step;
		step--;
	}
	delta_x += end.x;
	delta_y += end.y;
	delta_x -= start.x;
	delta_y -= start.y;
	return (sqrt(abs((delta_y * delta_y) + (delta_x * delta_x))));
}

int draw_square(t_frame *frame, t_pos pos, int size)
{
	int	w;
	int	h;
	int	tmp;

	w = 0;
	h = 0;
	while (w < size)
	{
		tmp = pos.y;
		h = 0;
		while (h < size)
		{
			draw_pixel(frame, pos.x, tmp, 0x00FF0000);
			tmp++;
			h++;
		}
		pos.x++;
		w++;
	}
}
