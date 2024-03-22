/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:24:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/22 19:24:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

int	ray_cast(t_data *d, mlx_image_t *frm)
{
	int			x;
	t_raydata	r_d;
	putreport("IN RC\n");
	x = 0;
	while (x < frm->width)
	{
		r_d.camera.x = 2 * (x / (float)frm->width) - 1.0f;
		r_d.ray_dir.x = d->player.dir.x + d->player.pane.x * r_d.camera.x;
		r_d.ray_dir.y = d->player.dir.y + d->player.pane.y * r_d.camera.x; 
		r_d.pos.x = (int)d->player.pos.x;
		r_d.pos.y = (int)d->player.pos.y;
		r_d.is_hit = 0;

		if (r_d.ray_dir.x == 0)
			r_d.ray_dir.x = 1e30;
		r_d.delta_distant.x = fabs(1 / r_d.ray_dir.x);
		if (r_d.ray_dir.y == 0)
			r_d.ray_dir.y = 1e30;
		r_d.delta_distant.y = fabs(1 / r_d.ray_dir.y);

		if (r_d.ray_dir.x < 0)
		{
			r_d.step.x = -1;
			r_d.side_distant.x = \
			(d->player.pos.x - r_d.pos.x) * r_d.delta_distant.x;
		}
		else
		{
			r_d.step.x = 1;
			r_d.side_distant.x = \
			(r_d.pos.x + 1.0 - d->player.pos.x) * r_d.delta_distant.x;
		}
		if (r_d.ray_dir.y < 0)
		{
			r_d.step.y = -1;
			r_d.side_distant.y = \
			(d->player.pos.y - r_d.pos.y) * r_d.delta_distant.y;
		}
		else
		{
			r_d.step.y = 1;
			r_d.side_distant.y = \
			(r_d.pos.y + 1.0 - d->player.pos.y) * r_d.delta_distant.y;
		}
		putreport("ST RAY\n");
		while (r_d.is_hit == 0)
		{
			if (r_d.side_distant.x < r_d.side_distant.y)
			{
				r_d.side_distant.x += r_d.delta_distant.x;
				r_d.pos.x += r_d.step.x;
				r_d.hit_side = 0;
			}
			else
			{
				r_d.side_distant.y += r_d.delta_distant.y;
				r_d.pos.y += r_d.step.y;
				r_d.hit_side = 1;
			}
			if (d->maps_data->maps_array[r_d.pos.y][r_d.pos.x] != '0')
				r_d.is_hit = 1;
		}
		putreport("END RC\n");

		if (r_d.hit_side == 0)
			r_d.perp_wall_distant = (r_d.side_distant.x - r_d.delta_distant.x);
		else
			r_d.perp_wall_distant = (r_d.side_distant.y - r_d.delta_distant.y);

		r_d.line_hight = (int)(frm->height / r_d.perp_wall_distant);
		r_d.line_s = -r_d.line_hight / 2 + frm->height / 2;
		if (r_d.line_s < 0)
			r_d.line_s = 0;
		r_d.line_e = (r_d.line_hight / 2) + (frm->height / 2);
		if (r_d.line_e >= frm->height)
			r_d.line_e = frm->height - 1;

		if (r_d.hit_side == 1)
			r_d.color = get_rgb(255, 0, 0, 1000);
		else
			r_d.color = get_rgb(255,0 ,0, 500);
		putreport("R data clear\n");
		draw_verline(frm, x, r_d.line_s, r_d.line_e, r_d.color);
		putreport("DRAW VERLINE\n");
		x++;
	}
	putreport("RC DONE LOOP\n");
}