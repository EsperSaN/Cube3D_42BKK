/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:54:45 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/17 01:04:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cube.h"
#define BUFFER_SIZE 1

int		is_same_str(char *s1, char *s2);
int		ft_isspace(char c);
int 	ft_is_map (char *str);
int		ft_get_color(t_data *data, char *str, int mode);
int		file_reader(t_data *data, int fd);
void	ft_floodfill(t_data *data, char **array);
int 	is_mapdata_valid(t_data *data);
t_maps	*maps_parser(t_data *data, char *file_name);

#endif