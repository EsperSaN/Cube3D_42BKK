/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:51:17 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/17 00:51:46 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

void	ft_floodfill_util(t_data *data, char **array, int x, int y)
{
	int h=data->maps_data->maps_height;
	int w=data->maps_data->maps_width;

	if (array[x][y] == '8')
	{
		printf("MAP not good [%c]\n", array[x][y]);
		data->maps_data->fl_status = 0;
	}
	if (array[x][y] == '0' && (x == 0 || y == 0 || y == w-1 || x == h-1))
	{
		printf("MAP not good [%c] %d %d\n", array[x][y] ,x, y);
		data->maps_data->fl_status = 0;
	}
	if (array[x][y] && array[x][y] == '0')
	{
		array[x][y] = 'x';
		ft_floodfill_util(data, array, x + 1, y);
		ft_floodfill_util(data, array, x - 1, y);
		ft_floodfill_util(data, array, x, y + 1);
		ft_floodfill_util(data, array, x, y - 1);
	}
}

void	ft_floodfill(t_data *data, char **array)
{
	int y=data->maps_data->player_pos.y;
	int x=data->maps_data->player_pos.x;
	//printf("%c\n", data->maps_data->maps_array[y][x]);
	ft_floodfill_util(data, array, x, y);
}