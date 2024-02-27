/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/27 21:21:59 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utill.h"

int		init_mlx(t_data *data, int screen_hight, int screen_width)
{
	data->mlx = mlx_init();
	//data->game_window = mlx_new_window(data->mlx, screen_hight, screen_width, WIN_TITLE);
}

int	init_data(t_data *data)
{
	data->mlx = NULL;
	data->game_window = NULL;
	data->data_window = NULL;
	data->raw_data = NULL;
	data->maps_data = ft_calloc(sizeof(t_maps), 1);
	data->maps_data->texture = ft_calloc(sizeof(t_texture), 1);
	if (data->maps_data == NULL || data->maps_data->texture == NULL)
		return (0);
	return(1);
}