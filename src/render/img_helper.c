/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:52:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/28 12:04:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	clear_frame(mlx_image_t *frm, int color)
{
	int	y;
	int	x;

	y = 0;
	putreport("int clear_frame");
	while (y < frm->width)
	{
		x = 0;
		while (x < frm->height)
		{
			mlx_put_pixel(frm, y, x, color);
			x++;
		}
		y++;
	}
}