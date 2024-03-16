/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:58:27 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 22:27:41 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	draw_square(mlx_image_t *frame, t_pos pos, int size, int color)
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
			mlx_put_pixel(frame, pos.x, tmp, color);
			tmp++;
			h++;
		}
		pos.x++;
		w++;
	}
}

int	draw_verline(mlx_image_t *frame, int x, int y, int to_y, int color)
{
	int	tmp;

	while (y++ < to_y)
		mlx_put_pixel(frame, x, y, color);
}

int	draw_line(mlx_image_t *frame, t_pos start, t_pos end, char **maps, int *hit)
{
	float	step;
	float	delta_x;
	float	delta_y;
	float	x_step;
	float	y_step;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	x_step = delta_x / step;
	y_step = delta_y / step;
	int tmp = step;
	int trigger = 0;
	while (step > 0)
	{
		if (maps[(int)start.y / 26][(int)start.x/26] != '0')
		{
			trigger = 1;
			break;
		}
		mlx_put_pixel(frame, (int)start.x, (int)start.y,  get_rgb(0,22,0,1000));
		start.x = start.x + x_step;
		start.y = start.y + y_step;
		step--;
	}
	delta_x += end.x;
	delta_y += end.y;
	delta_x -= start.x;
	delta_y -= start.y;
	if (trigger == 1)
		return (sqrt(abs((delta_y * delta_y) + (delta_x * delta_x))));
	else
		return 0;
}