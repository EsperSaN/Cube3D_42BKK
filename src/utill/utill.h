/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:04:15 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/15 22:28:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILL_H
# define UTILL_H

# include "../cube.h"
# include "./error_msg.h"

void	puterror(char *error_msg);
void	putreport(char *msg);
float	get_rad(float deg);
int		get_rgb(int r, int g, int b, int a);
void	print_maps_data(char **maps);
int		init_data(t_data *data, char *maps_file);
int		clear_close(t_data *d);
#endif
