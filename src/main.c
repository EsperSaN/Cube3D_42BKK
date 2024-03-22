/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/22 19:22:18 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"

// int main(int ac, char **av)
// {
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

	if (ac != 2)
		return (puterror(NO_ARG), FAIL);
	if (init_data(&data, av[1]) != SUCCESS)
		return (puterror(INIT_FAIL), FAIL);
	clear_frame(data.game_frm, get_rgb(255, 255, 255, 1000));
	clear_frame(data.map_frm, get_rgb(0, 0, 0, 1000));
	putreport("CLEAR FRME DONE\n");
	// draw_maps(&data, data.map_frm);
	// print_maps_data(data.maps_data->maps_array);
	// mlx_texture_t *t = mlx_load_png("./src/pics/mossy.png");
	// mlx_image_t *m = mlx_texture_to_image(data.mlx, t);
	// mlx_image_t *gg = mlx_new_image(data.mlx, 100, 100);

	// int i = 10;
	// int uu =0;
	// int j = 0;
	// int c = 0;
	// printf("width is %d height is %d bpp is %d\n", t->width, t->height, t->bytes_per_pixel);
	

	// for (int k = 0; k < t->height; k++)
	// {
	// 	for (j = 0; j < t->width; j++)
	// 	{
	// 		unsigned char r = t->pixels[c];
	// 		unsigned char g = t->pixels[c + 1];
	// 		unsigned char b = t->pixels[c + 2];
	// 		unsigned char a = t->pixels[c + 3];
	// 		int color = get_rgb(r, g, b ,a);
	// 		mlx_put_pixel(gg, j, k, color);
	// 		c += t->bytes_per_pixel;
	// 	}
	// }
	// for (j = 0; j < t->width * 4 ; j += 4)
	// {
	// 	unsigned char r = t->pixels[j];
	// 	unsigned char g = t->pixels[j + 1];
	// 	unsigned char b = t->pixels[j + 2];
	// 	unsigned char a = t->pixels[j + 3];
	// 	int color = get_rgb(r, g, b ,a);
	// 	mlx_put_pixel(m, uu++, i,color);
	// };
	// mlx_image_to_window(data.mlx, gg, 0, 0);
	// mlx_image_to_window(data.mlx, m, 0, 100);
	//mlx_image_t *tt = mlx_texture_to_image(data.mlx, t);
	// mlx_image_to_window(data.mlx, tt, 0 ,0);
	mlx_loop_hook(data.mlx, render_frame, (void *)&data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.game_frm);
	mlx_delete_image(data.mlx, data.map_frm);
	mlx_terminate(data.mlx);
}
