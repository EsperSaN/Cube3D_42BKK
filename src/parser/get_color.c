/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:55:42 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/17 01:15:50 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

int	ft_get_color(t_data *data, char *str, int mode)
{
	char	**num;
	int		i;

	num = ft_split(str, ',');
	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (0);//error not 0-255
		i++;
	}
	if (i != 3)
		return (0);//error not 3 elements
	i = 0;
	while (num[i])
	{
		if (mode == 'f')
		{
			if (data->maps_data->texture->floor[i] == -1)
				data->maps_data->texture->floor[i] = ft_atoi(num[i]);
			else
				return (0);//duplicate error
		}
		if (mode == 'c')
		{
			if (data->maps_data->texture->ceil[i] == -1)
				data->maps_data->texture->ceil[i] = ft_atoi(num[i]);
			else
				return (0);//duplicate error
		}
		i++;
	}
	return (1);
}
