/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 15:46:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_data	data;

	if(init_data(&data) == FAIL)
		return (puterror("FAILL TO INIT DATA"), 0);
	data.maps_data = maps_parser(av[1]);
	int i;
	i = 0;
	while (data.maps_data->maps_array[i])
	{
		int j = 0;
		while (data.maps_data->maps_array[i][j] != NULL)
		{
			printf("%c",data.maps_data->maps_array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	data.player.pos.x = 100;
	data.player.pos.y = 100;
	data.player.angle = 0;
	data.key.is_keypress = 0;
	data.maps_data->maps_hight = i--;
	data.maps_data->maps_width = (ft_strlen(data.maps_data->maps_array[0]));
	printf("w = %d h = %d\n" ,data.maps_data->maps_width ,data.maps_data->maps_hight);
	printf("start init\n");
	init_mlx(&data, SCREEN_HIGHT, SCREEN_WIDTH);
	printf("init fin\n");
	data.game_window = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HIGHT, WIN_TITLE);
	printf("data win with %d and %d\n",data.maps_data->maps_width, data.maps_data->maps_hight);
	data.data_window = mlx_new_window(data.mlx, data.maps_data->maps_width * MINIMAPS_SCALE, data.maps_data->maps_hight * MINIMAPS_SCALE, "data");
	printf("init fin\n");
	control(&data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
}
