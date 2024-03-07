/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/04 23:32:21 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utill.h"

int		init_mlx(t_data *data, int screen_hight, int screen_width)
{
	data->mlx = mlx_init();
}

int	init_data(t_data *data)
{
	data->mlx = NULL;
	data->game_window = NULL;
	data->data_window = NULL;
	data->key.a_key = 0;
	data->key.s_key = 0;
	data->key.d_key = 0;
	data->key.w_key = 0;
	data->key.left_key = 0;
	data->key.right_key = 0;
	data->maps_data = ft_calloc(sizeof(t_maps), 1);
	data->maps_data->texture = ft_calloc(sizeof(t_texture), 1);
	if (data->maps_data == NULL || data->maps_data->texture == NULL)
		return (0);
	return(1);
}