/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:44:11 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/15 17:40:43 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
#define INVALID_FILE "The given file must contain .cub extention"
#define HIGHT 0
#define WIDTH 1
#define FILE_EXT ".cub"

int	is_same_str(char *s1, char *s2)
{
	int	ret;

	ret = 1;
	if (!s1 || !s2)
		return (0);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			ret = 0;
		s2++;
		s1++;
	}
	if (*s1 != '\0' || *s2 != '\0')
		ret = 0;
	return (ret);
}

int	is_file_readable(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror(file_name), 0);
	if (fd > 0)
		close(fd);
	return (1);
}

int	is_right_extention(char *file_name, char *extention)
{
	if (!is_same_str(extention, ft_strrchr(file_name, '.')))
		return (0);
	return (1);
}

int	is_file_valid(char *file_name)
{
	if (!file_name)
		return (puterror("File Error : NULL"), 0);
	if (!is_right_extention(file_name, FILE_EXT))
		return (puterror(INVALID_FILE), 0);
	if (!is_file_readable(file_name))
		return (0);
	return (puterror("File is Valid"), 1);
}

int	file_reader(t_var *data, int fd)
{
	char	*tmp;
	char	*data;
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	data = ft_calloc(sizeof(char), 1);
	while (read_count > 0)
	{
		tmp = data;
		read_count = read(fd, buffer, BUFFER_SIZE);
		data = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (read_count < -1)
		perror("FILE READER : ");
	data->raw_data = ft_split(data, '\n');
	free(data);
	if (data->raw_data == NULL)
		return (perror("Raw_data"), 0);
	return (puterror("File Reader done."), 1);
}

int	maps_parser(t_var *data, char *file_name)
{
	int		fd;

	if (!is_file_valid(file_name))
		return (0);
	fd = open(file_name, O_RDONLY | O_CLOEXEC);
	if (fd < 0)
		return (perror("PARSER ERROR : "), 0);
	if (!file_reader(data, fd))
		return (puterror("VALID , READ : not right"), 0);
	if (!is_mapdata_valid(data))
		return (puterror("data in file not good"), 0);
	if (!is_map_playable(data->maps_data))
		return (puterror("maps is not playable"), 0);
	return (1);
}
