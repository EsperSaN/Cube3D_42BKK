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

int	ft_get_color(t_var *data, char *str, int mode)
{
	char **num;
	int	i;

	num = ft_split(str, ',');
	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (0);//error not 0-255
		i++;
	}
	if (i!=3)
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

int	ft_isspace(char c)
{
	if (c == '\r' || c == '\n' || c == '\f' )
		return (1);
	else if (c == '\v' || c == '\t' || c == ' ' )
		return (1);
	return (0);
}

int is_mapdata_valid(t_var *data)
{
	int i;
	int j;
	// int k=-1;
	char **str;
	t_maps	*maps;
	maps = ft_calloc(sizeof(t_maps), 1);
	data->maps_data = maps;
	t_texture *texture;
	texture = ft_calloc(sizeof(t_texture), 1);
	data->maps_data->texture = texture;

	data->maps_data->texture->floor[0] = -1;
	data->maps_data->texture->floor[1] = -1;
	data->maps_data->texture->floor[2] = -1;
	data->maps_data->texture->ceil[0] = -1;
	data->maps_data->texture->ceil[1] = -1;
	data->maps_data->texture->ceil[2] = -1;
	
	i = 0;
	while(data->raw_data[i])
	{
		j = 0;
		while (data->raw_data[i][j])
		{
			if (!ft_isspace(data->raw_data[i][j]))
				break;
			j++;
		}
		if (j == ft_strlen(data->raw_data[i]))
			return (0);//error space only
		i++;
	}
	//each element is readable
		//file size and dimension
	i = 0;
	
	while(data->raw_data[i])
	{
		// split with " " then use next index if it equal to "NO" DONE
		str = ft_split(data->raw_data[i], ' ');
		j = 0;
		while(str[j])
		{
			//check null before assign DONE
				//case "NO NO ./path_to_the_north_texture" throw error
				//check openable file
			if (is_same_str(str[j], "NO"))
			{
				if (data->maps_data->texture->north)
					return (0);//error duplicate
				else
					data->maps_data->texture->north = str[j+1];
			}	
			else if (is_same_str(str[j], "SO"))
			{
				if (data->maps_data->texture->south)
					return (0);//error duplicate
				else
					data->maps_data->texture->south = str[j+1];
			}
			else if (is_same_str(str[j], "WE"))
			{
				if (data->maps_data->texture->west)
					return (0);//error duplicate
				else
					data->maps_data->texture->west = str[j+1];
			}
			else if (is_same_str(str[j], "EA"))
			{
				if (data->maps_data->texture->east)
					return (0);//error duplicate
				else
					data->maps_data->texture->east = str[j+1];
			}
			else if (is_same_str(str[j], "F"))
			{
				//get num count it -> check it -> assign DONE
				if(!ft_get_color(data, str[j+1], 'f'))
					return (0);//error assign
					//case "color 255, 0,0" throw error ?
			}
			else if (is_same_str(str[j], "C"))
			{
				//get num count it -> check it -> assign
				if(!ft_get_color(data, str[j+1], 'c'))
					return (0);//error assign
					//case "color 255, 0,0" throw error ?
			}
			//else
			// {
			// 	if (k == -1 && data->maps_data->texture->north && data->maps_data->texture->south 
			// 		&& data->maps_data->texture->west && data->maps_data->texture->east
			// 		&& data->maps_data->texture->floor[0]!=-1 && data->maps_data->texture->floor[2]!=-1
			// 		&& data->maps_data->texture->floor[1]!=-1 && data->maps_data->texture->ceil[0]!=-1
			// 		&& data->maps_data->texture->ceil[1]!=-1 && data->maps_data->texture->ceil[2]!=-1)
			// 		k = i+1;
			// }
			j++;
		}
		i++;
	}
	// printf("k = %d\n", k);
	
	printf("NO : [%s]\n", data->maps_data->texture->north);
	printf("SO : [%s]\n", data->maps_data->texture->south);
	printf("WE : [%s]\n", data ->maps_data->texture->west);
	printf("EA : [%s]\n", data->maps_data->texture->east);
	printf("Floor : [%d ", data->maps_data->texture->floor[0]);
	printf("%d ", data->maps_data->texture->floor[1]);
	printf("%d]\n", data->maps_data->texture->floor[2]);
	printf("Ceil : [%d ", data->maps_data->texture->ceil[0]);
	printf("%d ", data->maps_data->texture->ceil[1]);
	printf("%d]\n", data->maps_data->texture->ceil[2]);

	//check did we got all data
	
	if (!data->maps_data->texture->north || !data->maps_data->texture->south 
		|| !data->maps_data->texture->west || !data->maps_data->texture->east
		|| data->maps_data->texture->floor[0]==-1 || data->maps_data->texture->floor[2]==-1
		|| data->maps_data->texture->floor[1]==-1 || data->maps_data->texture->ceil[0]==-1
		|| data->maps_data->texture->ceil[1]==-1 || data->maps_data->texture->ceil[2]==-1)
		return (0);//error missing some data

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

	printf("\n");
	i = 6;
	
	while(data->raw_data[i])
	{
		printf("[%s]\n", data->raw_data[i]);
		i++;
	}


	return (1);
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

t_maps *maps_parser(t_var *data, char *file_name)
{
	int		fd;
	t_maps	*maps_data;

	maps_data = ft_calloc(sizeof(t_maps), 1);
	if (!is_file_valid(file_name))
		return (0);
	fd = open(file_name, O_RDONLY | O_CLOEXEC);
	if (fd < 0)
		return (perror("PARSER ERROR : "), NULL);
	if (!file_reader(data, fd))
		return (puterror("VALID , READ : not right"), NULL);
	if (!is_mapdata_valid(data))
		return (puterror("data in file not good"), NULL);
	//if (!is_map_playable(data->maps_data))
	//	return (puterror("maps is not playable"), 0);
	return (maps_data);
}
