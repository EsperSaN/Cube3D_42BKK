/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 10:28:12 by pruenrua         ###   ########.fr       */
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
		data->key.w_key = PRESS;
	if (key_press == S)
		data->key.s_key = PRESS;
	if (key_press == A)
		data->key.a_key = PRESS;
	if (key_press == D)
		data->key.d_key = PRESS;
	if (key_press == LEFT_ARROW)
		data->key.left_key = PRESS;
	if (key_press == RIGHT_ARROW)
		data->key.right_key = PRESS;
	data->key.is_keypress = 1;
}

int key_release(int key_press, t_data *data)
{
	printf("key [%d] releasepress\n", key_press);
	if (key_press == W)
		data->key.w_key = RELEASE;
	if (key_press == S)
		data->key.s_key = RELEASE;
	if (key_press == A)
		data->key.a_key = RELEASE;
	if (key_press == D)
		data->key.d_key = RELEASE;
	if (key_press == LEFT_ARROW)
		data->key.left_key = RELEASE;
	if (key_press == RIGHT_ARROW)
		data->key.right_key = RELEASE;
	data->key.is_keypress = 0;

	if (key_press == ESC)
		close_game(data);
}

int control(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->data_window, ON_KEYDOWN, KEYPRESSMASK, key_press, data);
	mlx_hook(data->data_window, ON_KEYUP, KEYRELEASEMASK, key_release, data);
	mlx_hook(data->data_window, ON_DESTROY, 0L, close_game, data);
}

