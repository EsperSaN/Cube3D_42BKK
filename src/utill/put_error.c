/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:12 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/16 23:48:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utill.h"

void	putreport(char *msg)
{
	write(2, "REPORT: ", 8);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return ;
}

void	puterror(char *error_msg)
{
	write(2, "ERROR : ", 6);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
}

float	get_rad(float deg)
{
	return (deg * (PI / 180.f));
}

int	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	print_maps_data(char **maps)
{
	int	i;

	i = 0;
	printf("MAPS IS \n");
	while (maps[i])
	{
		printf(">>|%s|<<\n", maps[i]);
		i++;
	}
}
