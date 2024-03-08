/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:44:11 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/08 01:36:26 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
#define INVALID_FILE "The given file must contain .cub extention"
#define HIGHT 0
#define WIDTH 1
#define FILE_EXT ".cub"

int is_mapdata_valid(t_var *data)
{
	int i = 0;
	t_maps	maps;
	data->maps_data = &maps;
	t_texture texture;
	data->maps_data->texture = &texture;

	printf("raw map data : \n");
	while(data->raw_data[i])
	{
		printf("%s\n", data->raw_data[i]);
		i++;
	}
	//each element is readable
		//file size and dimension
	i = 0;
	while(data->raw_data[i])
	{
		if (data->raw_data[i][0] == 'N' && data->raw_data[i][1] == 'O')
			data->maps_data->texture->north = data->raw_data[i];
		if (data->raw_data[i][0] == 'S' && data->raw_data[i][1] == 'O')
			data->maps_data->texture->south = data->raw_data[i];
		if (data->raw_data[i][0] == 'W' && data->raw_data[i][1] == 'E')
			data->maps_data->texture->west = data->raw_data[i];
		if (data->raw_data[i][0] == 'E' && data->raw_data[i][1] == 'A')
			data->maps_data->texture->east = data->raw_data[i];
		// if (data->raw_data[i][0] == 'F')
		// {

		// }
		// if (data->raw_data[i][0] == 'C')
		// {

		// }
		i++;
	}
	printf("[%s]\n", data->maps_data->texture->north);
	printf("[%s]\n", data->maps_data->texture->south);
	printf("[%s]\n", data->maps_data->texture->west);
	printf("[%s]\n", data->maps_data->texture->east);
	printf("[%d ", data->maps_data->texture->floor[0]);
	printf("%d ", data->maps_data->texture->floor[1]);
	printf("%d]\n", data->maps_data->texture->floor[2]);
	printf("[%d ", data->maps_data->texture->ceil[0]);
	printf("%d ", data->maps_data->texture->ceil[1]);
	printf("%d]\n", data->maps_data->texture->ceil[2]);

	// color only int
	//possible char and it's limitation
	// while (map[i])
	// {
	// 	while (map[i][j])
	// 	{
	// 		//check char
	// 		/* code */
	// 	}
		
	// 	/* code */
	// }
	
	//surrounded by wall
	//floodfill_check?
	//order of elements
	//space between elements
	//save data (size, 2d array)
	return (1);
}

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
	char	*chdata;
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	chdata = ft_calloc(sizeof(char), 1);
	while (read_count > 0)
	{
		tmp = chdata;
		read_count = read(fd, buffer, BUFFER_SIZE);
		chdata = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (read_count < -1)
		perror("FILE READER : ");
	data->raw_data = ft_split(chdata, '\n');
	free(chdata);
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
	//if (!is_map_playable(data->maps_data))
	//	return (puterror("maps is not playable"), 0);
	return (1);
}
