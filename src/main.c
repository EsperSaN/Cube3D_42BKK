/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/27 21:21:55 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
// #define KEY_DOWN 
// #define KEY_RIGHT 
// #define KEY_LEFT 
// #define KEY_UP 
int control(int key_press, t_data *data)
{
	printf("key [%d] press\n", key_press);
	// if (key_press == )
}

int	main(int ac, char **av)
{
/*	if (ac != 2 || !av[1] || av[1] == NULL)
		return (puterror(INVALID_ARG), 1);
	if (!is_right_extention(av[1]))
		return (puterror(INVALID_FILE), 2);
	printf("HELLO CUBE\n");*/
	t_data data;

	if(init_data(&data) == FAIL)
		return (puterror("FAILL TO INIT DATA"), 0);
	// data.maps_data = maps_parser(&data, av[1]);
	init_mlx(&data, SCREEN_HIGHT, SCREEN_WIDTH);
	data.game_window = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HIGHT, WIN_TITLE);
	printf("mlx\nwin = %p\nptr = %p\n", data.mlx, data.game_window);
	// mlx_key_hook(data.game_window ,control, &data);
	// mlx_loop_hook(data.mlx, render_frame, &data);
	render_frame(&data);
	mlx_loop(data.mlx);
}
