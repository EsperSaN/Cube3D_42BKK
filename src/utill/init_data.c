/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/14 20:44:26 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utill.h"

int clear_close(t_data *d)
{
	mlx_close_window(d->mlx);
}

void rotate_player(t_data *d)
{
	t_pos tmp;
	float a;

	a = get_rad(90);
	tmp.x = d->player.dir.x;
	tmp.y = d->player.dir.y;
	d->player.dir.x = d->player.dir.x * cos(a) - d->player.dir.y * sin(a);
	d->player.dir.y = tmp.x * sin(a) + d->player.dir.y * cos(a);
	tmp.x = d->player.pane.x;
	d->player.pane.x = d->player.pane.x * cos(a) - d->player.pane.y * sin(a);
	d->player.pane.y = tmp.x * sin(a) + d->player.pane.y * cos(a);
}

int	get_player_pos(t_data *d)
{
	d->player.pos.x = 10 - 0.5;
	d->player.pos.y = 10 - 0.5;
	d->player.dir.x = 1;
	d->player.dir.y = 0;
	d->player.pane.x = 0;
	d->player.pane.y = 0.66;
	rotate_player(d);
	printf("init dir x = %f y = %f\n", d->player.dir.x, d->player.dir.y);
	return (1);
}

int	init_data(t_data *data, char *maps_file)
{
	data->mlx = NULL;
	data->maps_data = NULL;
	data->player.fov = FIELD_OF_VIEW;
	data->maps_data = maps_parser(maps_file);
	if (data->maps_data == NULL)
		return (puterror(PARSER_FAIL), FAIL);
	data->maps_data->maps_width = ft_strlen(data->maps_data->maps_array[0]);
	int i ;
	for (i = 0; data->maps_data->maps_array[i]; i++);
	data->maps_data->maps_hight = i;
	putreport("get maps done");
	get_player_pos(data);
	data->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HIGHT, WIN_TITLE, FALSE);
	if (data->mlx == NULL)
		return (puterror(MLX_FAIL), FAIL);
	putreport("get mlx done");
	data->game_frm = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	data->map_frm = mlx_new_image(data->mlx, SCREEN_WIDTH / 2, SCREEN_HIGHT);
	mlx_image_to_window(data->mlx, data->game_frm, 0, 0);
	//mlx_image_to_window(data->mlx, data->map_frm, 0, 0);
	putreport("get frm done");
	return (SUCCESS);
}
