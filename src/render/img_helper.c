/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:52:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/14 21:58:50 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	clear_frame(mlx_image_t *frm, int color)
{
	int	y;
	int	x;

	y = 0;
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