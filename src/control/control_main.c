/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 21:42:53 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./control.h"

int close_game(t_data *data)
{
	printf("BYYYYEEEEE");
	mlx_destroy_window(data->mlx, data->game_window);
	exit (1);
}

int key_press(int key_press, t_data *data)
{
	printf("key [%d] press\n", key_press);
	if (key_press == W)
		data->w_key = 1;
	if (key_press == S)
		data->s_key = 1;
	if (key_press == A)
		data->a_key = 1;
	if (key_press == D)
		data->d_key = 1;
}

int key_release(int key_press, t_data *data)
{
	printf("key [%d] releasepress\n", key_press);
	if (key_press == W)
		data->w_key = 0;
	if (key_press == S)
		data->s_key = 0;
	if (key_press == A)
		data->a_key = 0;
	if (key_press == D)
		data->d_key = 0;

	if (key_press == ESC)
		close_game(data);
}

int control(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->game_window, ON_KEYDOWN, KEYPRESSMASK, key_press, data);
	mlx_hook(data->game_window, ON_KEYUP, KEYRELEASEMASK, key_release, data);
	mlx_hook(data->game_window, ON_DESTROY, 0L, close_game, data);
}

