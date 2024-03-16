/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:20 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 20:30:26 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	draw_player(t_data *d, mlx_image_t *frm, int scale)
{
	t_pos	p;
	t_pos	l;
	t_pos	r;
	t_pos	n;
	t_pos	dir_mul;
	int		max_sight;

	max_sight = 10000;
	dir_mul.x = d->player.dir.x * max_sight;
	dir_mul.y = d->player.dir.y * max_sight;
	p.x = d->player.pos.x * scale;
	p.y = d->player.pos.y * scale;
	n.x = (p.x  + dir_mul.x);
	n.y = (p.y  + dir_mul.y);
	r.x = p.x - dir_mul.y;
	r.y = p.y + dir_mul.x;
	l.x = p.x + dir_mul.y;
	l.y = p.y - dir_mul.x;
	// draw_square(frm, p, 8, get_rgb(0, 0, 255, 1000));
	// draw_square(frm, n, 5, get_rgb(0, 255, 0, 1000));
	// draw_square(frm, r, 5, get_rgb(125,125,125, 1000));
	// draw_square(frm, l, 5, get_rgb(200,200,200, 1000));
	t_pos ra;

	int x = 0;
	float a = -45;
	float t;
	int hit;
	hit = 0;
	while (x < d->game_frm->width)
	{
		t = d->player.angle + a;
		ra.x = (p.x) + ((cosf(get_rad(t))) * max_sight);
		ra.y = (p.y) + ((sinf(get_rad(t))) * max_sight);
		int lineH = draw_line(frm, p, ra, d->maps_data->maps_array, &hit);
		// draw_verline(d->game_frm, x, 0, d->game_frm->height / 2, get_rgb(100,100,100, 200));
		// draw_verline(d->game_frm, x, d->game_frm->height / 2, d->game_frm->height / 2, get_rgb(200,0,100, 200));
		// lineH = lineH * cosf(get_rad(fabs(d->player.angle)));
		// lineH = fabs(lineH);
		// if (hit == 1)
		// 	draw_verline(d->game_frm, x ,(d->game_frm->height / 2) - (lineH / 2), lineH, get_rgb(0, 255, 0, 1000));
		// else
		// 	draw_verline(d->game_frm, x ,(d->game_frm->height / 2) - (lineH / 2), lineH, get_rgb(0, 0, 255, 1000));
		a += (90.0 / d->game_frm->width);
		x++;
	}
	// draw_line(frm, p, r, d->maps_data->maps_array);
	// draw_line(frm, p, l, d->maps_data->maps_array);
}

int		get_maps_scale(t_data *d, mlx_image_t *img)
{
	int	scale_x;
	int	scale_y;
	int	scale;

	scale_x = img->width / d->maps_data->maps_width;
	scale_y = img->height / d->maps_data->maps_hight;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

void	draw_maps(t_data *d, mlx_image_t *img)
{
	int		i;
	int		j;
	t_pos	pos;
	int		scale;

	scale = get_maps_scale(d, img);
	i = 0;
	pos.x = 0;
	while (i < d->maps_data->maps_width)
	{
		pos.y = 0;
		j = 0;
		while (j < d->maps_data->maps_width)
		{
			if (d->maps_data->maps_array[j][i] != FLOOR)
				draw_square(img, pos, scale - 1, get_rgb(255, 0, 0, 1000));
			else
				draw_square(img, pos, scale - 1, get_rgb(255, 255, 255, 500));
			pos.y += scale;
			j++;
		}
		pos.x += scale;
		i++;
	}
	draw_player(d, img, scale);
}