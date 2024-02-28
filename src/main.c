/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/28 20:38:41 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_data data;

	if(init_data(&data) == FAIL)
		return (puterror("FAILL TO INIT DATA"), 0);
	// data.maps_data = maps_parser(&data, av[1]);
	data.posx = 1;
	data.posy = 1;
	init_mlx(&data, SCREEN_HIGHT, SCREEN_WIDTH);
	data.game_window = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HIGHT, WIN_TITLE);
	printf("mlx\nwin = %p\nptr = %p\n", data.mlx, data.game_window);
	control(&data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	//render_frame(&data);
	mlx_loop(data.mlx);
}
