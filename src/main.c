/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 22:23:00 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"


int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (puterror(NO_ARG), FAIL);
	if (init_data(&data, av[1]) != SUCCESS)
		return (puterror(INIT_FAIL), FAIL);
	clear_frame(data.game_frm, get_rgb(255, 255, 255, 1000));
	clear_frame(data.map_frm, get_rgb(0, 0, 0, 1000));
	draw_maps(&data, data.map_frm);
	print_maps_data(data.maps_data->maps_array);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.game_frm);
	mlx_delete_image(data.mlx, data.map_frm);
	mlx_terminate(data.mlx);
}
