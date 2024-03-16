/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 23:41:23 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./control.h"

int	player_side_move(t_data *d, int dir)
{
	t_pos	mdr;
	char	**maps;

	maps = d->maps_data->maps_array;
	mdr.x = d->player.dir.x * (MOVE_SPEED / 2);
	mdr.y = d->player.dir.y * (MOVE_SPEED / 2);
	if (dir == LEFT)
	{
		if (maps[(int)(d->player.pos.y - mdr.x)][(int)d->player.pos.x] == '0')
			d->player.pos.y -= mdr.x;
		if (maps[(int)d->player.pos.y][(int)(d->player.pos.x + mdr.y)] == '0')
			d->player.pos.x += mdr.y;
	}
	if (dir == RIGHT)
	{
		if (maps[(int)(d->player.pos.y + mdr.x)][(int)d->player.pos.x] == '0')
			d->player.pos.y += mdr.x;
		if (maps[(int)d->player.pos.y][(int)(d->player.pos.x - mdr.y)] == '0')
			d->player.pos.x -= mdr.y;
	}
}

int player_rotate(t_data *d, int dir)
{
	t_pos tmp;
	float a;

	a = get_rad(ROT_SPEED);
	tmp.x = d->player.dir.x;
	tmp.y = d->player.dir.y;
	if (dir == LEFT)
	{
		a = -1 * a;
		d->player.dir.x = d->player.dir.x * cos(a) - d->player.dir.y * sin(a);
		d->player.dir.y = tmp.x * sin(a) + d->player.dir.y * cos(a);
		tmp.x = d->player.pane.x;
		d->player.pane.x = d->player.pane.x * cos(a) - d->player.pane.y * sin(a);
		d->player.pane.y = tmp.x * sin(a) + d->player.pane.y * cos(a);
	}
	if (dir == RIGHT)
	{
		d->player.dir.x = d->player.dir.x * cosf(a) - d->player.dir.y * sinf(a);
		d->player.dir.y = tmp.x * sinf(a) + d->player.dir.y * cosf(a);
		tmp.x = d->player.pane.x;
		d->player.pane.x = d->player.pane.x * cosf(a) - d->player.pane.y * sinf(a);
		d->player.pane.y = tmp.x * sinf(a) + d->player.pane.y * cosf(a);
	}
}

// int	player_rotate(t_data *d, int dir)
// {
// 	float	x;
// 	float	y;
// 	float	a;

// 	x = d->player.dir.x;
// 	y = d->player.dir.y;
// 	if (dir == LEFT)
// 		d->player.angle -= ROT_SPEED;
// 	if (dir == RIGHT)
// 		d->player.angle += ROT_SPEED;
// 	a = get_rad(d->player.angle);
// 	d->player.dir.x = cosf(a);
// 	d->player.dir.y = sinf(a);

// 	d->player.pane.x = cosf(a);
// 	d->player.pane.y = (d->player.pane.y * sinf(a));
// 	return (1);
// }

int	player_move(t_data *d, int dir)
{
	t_pos	mdr;
	char	**maps;

	maps = d->maps_data->maps_array;
	mdr.x = d->player.dir.x * (MOVE_SPEED / 2);
	mdr.y = d->player.dir.y * (MOVE_SPEED / 2);
	if (dir == UP)
	{
		if (maps[(int)(d->player.pos.y + mdr.y)][(int)d->player.pos.x] == '0')
			d->player.pos.y += mdr.y;
		if (maps[(int)d->player.pos.y][(int)(d->player.pos.x + mdr.x)] == '0')
			d->player.pos.x += mdr.x;
	}
	if (dir == DOWN)
	{
		if (maps[(int)(d->player.pos.y - mdr.y)][(int)d->player.pos.x] == '0')
			d->player.pos.y -= mdr.y;
		if (maps[(int)d->player.pos.y][(int)(d->player.pos.x - mdr.x)] == '0')
			d->player.pos.x -= mdr.x;
	}
}
// https://stackoverflow.com/questions/4780119/2d-euclidean-vector-rotations
int	key_hook(t_data *d)
{
	mlx_t	*mlx;
	int		trigger;

	trigger = 0;
	mlx = d->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		trigger = player_move(d, UP);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		trigger = player_side_move(d, LEFT);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		trigger = player_move(d, DOWN);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		trigger = player_side_move(d, RIGHT);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		trigger = player_rotate(d, LEFT);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		trigger = player_rotate(d, RIGHT);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		clear_close(d);
	return (trigger);
}
