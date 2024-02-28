/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:58:27 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 21:49:53 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	draw_pixel(t_frame *frame, int x, int y, int color)
{
	char	*adr;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > SCREEN_WIDTH - 1)
		x = x % (SCREEN_WIDTH - 1);
	if (y > SCREEN_HIGHT - 1)
		y = y % (SCREEN_HIGHT - 1);
	adr = frame->address;
	adr = frame->address + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int *)adr = color;
}

int	draw_verline(t_frame *frame, int x, int y, int to_y, int color)
{
	int	tmp;

	if (y > to_y)
	{
		tmp = to_y;
		to_y = y;
		y = tmp;
	}
	if (y < 0)
		y = 0;
	if (to_y > SCREEN_HIGHT)
		to_y = SCREEN_HIGHT;

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