/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/22 19:04:28 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	draw_floor(t_data *d, mlx_image_t *frm, int color)
{
	int x;

	x = 0;
	while (x < frm->width)
	{
		draw_verline(frm, x, frm->height / 2, frm->height, color);
		x++;
	}

}

void	draw_ceil(t_data *d, mlx_image_t *frm, int color)
{
	int x;

	x = 0;
	while (x < frm->width)
	{
		draw_verline(frm, x, 0, frm->height / 2, color);
		x++;
	}

}

int 	render_frame(t_data *d)
{
	if (key_hook(d) == 1);
	{
	clear_frame(d->map_frm, get_rgb(0, 0, 0, 1000));
	clear_frame(d->game_frm, get_rgb(0, 0, 0, 1000));
	//draw_maps(d, d->map_frm);
	draw_ceil(d, d->game_frm, get_rgb(255, 255, 255, 1000));
	draw_floor(d, d->game_frm, get_rgb(100, 100, 100, 1000));
	ray_cast(d, d->game_frm);
	}
}