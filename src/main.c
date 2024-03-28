/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/28 12:05:53 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"

// int main(int ac, char **av)
//{
// 	t_data mlx;
// 	t_tex *tex;


// 	mlx.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HIGHT, "ray", TRUE);
// 	tex = tex_baker("./src/pics/barrel.png");
// 	mlx_image_t	*m;
// 	m = mlx_new_image(mlx.mlx, SCREEN_WIDTH, SCREEN_HIGHT);
// 	for (int i = 0; i < tex->height; i++)
// 	{
// 		for (int j = 0; j < tex->width; j++)
// 			mlx_put_pixel(m, j, i, tex->tex_pixel[i][j]);
// 	}
// 	mlx_image_to_window(mlx.mlx, m, 0,0);
// 	mlx_loop(mlx.mlx);
// }
int	main(int ac, char **av)
{
	t_data	data;
	//t_data 	de;

	if (ac != 2)
		return (puterror(NO_ARG), FAIL);
	if (init_data(&data, av[1]) != SUCCESS)
		return (puterror(INIT_FAIL), FAIL);
	clear_frame(data.game_frm, get_rgb(255, 255, 255, 1000));
	putreport("CLEAR FRME DONE\n");
	mlx_loop_hook(data.mlx, render_frame, (void *)&data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.game_frm);
	mlx_terminate(data.mlx);
}
