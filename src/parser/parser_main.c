/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:44:11 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/07 14:51:33 by pruenrua         ###   ########.fr       */
/*   Updated: 2024/03/08 01:36:26 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
#define INVALID_FILE "The given file must contain .cub extention"
#define HIGHT 0
#define WIDTH 1
#define FILE_EXT ".cub"

int ft_is_map (char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'N'
		|| str[i] == 'S' || str[i] == 'E' || str[i] == 'W'
		|| str[i] == ' ')
			i++;
		else
			return (0);
	}
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

int	ft_check_endl(char *str)
{
	int	i;
	int	j;
	int	len;
	int flag;
	char *tmp;

	flag = 0;
	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '\n')
		{
			len = i - j - 1;
			if (len < 0)
				len = 0;
			tmp = ft_substr(str, j, len);
			//printf("[%s]\n", tmp);
			if(ft_is_map(tmp) && len > 0)
				flag = 1;
			//printf("%d %d\n", len, flag);
			if(len == 0 && flag)
				return(0);
			j = i + 1;
			free(tmp);
		}

		i++;
	}
	return(1);
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

void	ft_floodfill_util(t_var *data, char **array, int x, int y)
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

void	ft_floodfill(t_var *data, char **array)
{
	int y=data->maps_data->player_pos.y;
	int x=data->maps_data->player_pos.x;
	//printf("%c\n", data->maps_data->maps_array[y][x]);
	ft_floodfill_util(data, array, x, y);
}

int is_mapdata_valid(t_var *data)
{
	int i;
	int j;
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
	int k = 0;
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
		if(!ft_is_map(data->raw_data[i]))
			k++;
		else
			break;
		i++;
	}
	if (k != 6)
		return (0);// over data
	// printf("k = %d\n", k);
	//each element is readable
		//file size and dimension
	i = 0;
	
	while(data->raw_data[i])
	{
		// split with " " then use next index if it equal to "NO" DONE
		str = ft_split(data->raw_data[i], ' ');
		j = 0;
		while (str[j])
		{
			j++;
		}
		if (j!=2)
			break;//more than 2 elements
		j = 0;
		while(str[j] && k)
		{
			//check null before assign DONE
				//case "NO NO ./path_to_the_north_texture" throw error
				//check openable file
			//printf("%s\n", str[j]);
			if (is_same_str(str[j], "NO"))
			{
				if (data->maps_data->texture->north)
					return (0);//error duplicate
				else
				{
					data->maps_data->texture->north = str[j+1];
					break;
				}
			}	
			else if (is_same_str(str[j], "SO"))
			{
				if (data->maps_data->texture->south)
					return (0);//error duplicate
				else
				{
					data->maps_data->texture->south = str[j+1];
					break;
				}
			}
			else if (is_same_str(str[j], "WE"))
			{
				if (data->maps_data->texture->west)
					return (0);//error duplicate
				else
				{
					data->maps_data->texture->west = str[j+1];
					break;
				}
			}
			else if (is_same_str(str[j], "EA"))
			{
				if (data->maps_data->texture->east)
					return (0);//error duplicate
				else
				{
					data->maps_data->texture->east = str[j+1];
					break;
				}
			}
			else if (is_same_str(str[j], "F"))
			{
				//get num count it -> check it -> assign DONE
				if(!ft_get_color(data, str[j+1], 'f'))
					return (0);//error assign
				break;
					//case "color 255, 0,0" throw error yay
			}
			else if (is_same_str(str[j], "C"))
			{
				//get num count it -> check it -> assign
				if(!ft_get_color(data, str[j+1], 'c'))
					return (0);//error assign
				break;
					//case "color 255, 0,0" throw error yay
			}
			else
			 	return (0);//error not pattern
			j++;
		}
		k--;
		// if (data->maps_data->texture->north && data->maps_data->texture->south 
		// 	&& data->maps_data->texture->west && data->maps_data->texture->east
		// 	&& data->maps_data->texture->floor[0]!=-1 && data->maps_data->texture->floor[2]!=-1
		// 	&& data->maps_data->texture->floor[1]!=-1 && data->maps_data->texture->ceil[0]!=-1
		// 	&& data->maps_data->texture->ceil[1]!=-1 && data->maps_data->texture->ceil[2]!=-1)
		// 	break;
		i++;
	}
	
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

	// //check did we got all data
	
	// if (data->maps_data->texture->north && data->maps_data->texture->south 
	// 	&& data->maps_data->texture->west && data->maps_data->texture->east
	// 	&& data->maps_data->texture->floor[0]!=-1 && data->maps_data->texture->floor[2]!=-1
	// 	&& data->maps_data->texture->floor[1]!=-1 && data->maps_data->texture->ceil[0]!=-1
	// 	&& data->maps_data->texture->ceil[1]!=-1 && data->maps_data->texture->ceil[2]!=-1)
	// 	return (1);
	// else
	// 	return (0);//error missing some data

	i = 6;
	k = 0;
	while(data->raw_data[i])
	{
		j = 0;
		while(data->raw_data[i][j])
		{
			if (data->raw_data[i][j] == 'N' || data->raw_data[i][j] == 'S' 
				|| data->raw_data[i][j] == 'E' || data->raw_data[i][j] == 'W')
				{
					k++;
					data->maps_data->player_pos.y = i - 6;
					data->maps_data->player_pos.x = j;

				}
			if (k>1)
				return (0);//error duplicate spawn
			j++;
		}
		// printf("%s <%d>\n", data->raw_data[i], ft_strlen(data->raw_data[i]));
		i++;
	}
	i = 6;
	k = 0;
	while(data->raw_data[i])
	{
		if (!ft_is_map(data->raw_data[i]))
			return (0);//not 0 1 (ewns)   //CHECK DUP SPAWN
		k++;
		//printf("[%s]\n", data->raw_data[i]);
		//data->maps_data->maps_array=;
		i++;
	}
	data->maps_data->maps_array = (char **)malloc((sizeof(char *)) * (k + 1));
	data->maps_data->maps_array[k] = NULL;
	data->maps_data->maps_height = k;
	i = 6;
	k = 0;
	k = ft_strlen(data->raw_data[i]);
	while(data->raw_data[i])
	{
		if (ft_strlen(data->raw_data[i]) > k)
		{
			k = ft_strlen(data->raw_data[i]);
		}
		i++;
	}
	data->maps_data->maps_width = k;
	i = 0;
	while(data->raw_data[i])
	{
		data->maps_data->maps_array[i] = data->raw_data[i+6];
		i++;
	}
	i = 0;
	while(data->maps_data->maps_array[i])
	{
		printf("[%s] <%zu>\n", data->maps_data->maps_array[i], ft_strlen(data->maps_data->maps_array[i]));
		i++;
	}

	printf("width = [%d]\n",data->maps_data->maps_width);
	printf("height = [%d]\n",data->maps_data->maps_height);

	char **new_map;
	new_map = (char **)malloc((sizeof(char *)) * (data->maps_data->maps_height + 1));
	i = 0;
	while(i < data->maps_data->maps_height)
	{
		j = 0;
		new_map[i] = (char *)malloc((sizeof(char)) * (data->maps_data->maps_width + 1));
		while(j < data->maps_data->maps_width)
		{
			//printf("%c", data->maps_data->maps_array[i][j]);
			if (data->maps_data->maps_array[i][j] && data->maps_data->maps_array[i][j] != ' ')
			  	new_map[i][j] = data->maps_data->maps_array[i][j];
			else
			 	new_map[i][j] = '8';
			j++;
		}
		new_map[i][j] = '\0';
		//printf("\n");
		i++;
	}
	new_map[i] = NULL;

	i = 0;
	while(data->maps_data->maps_array[i])
	{
		j = 0;
		while(j < data->maps_data->maps_width)
		{
			printf("%c", new_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	printf("pos x = [%d]\n", data->maps_data->player_pos.x);
	printf("pos y = [%d]\n", data->maps_data->player_pos.y);

	data->maps_data->fl_status = 1;
	ft_floodfill(data, new_map);

	if (data->maps_data->fl_status)
		printf("yay nice map\n");
	else
		return (0);

	i = 0;
	while(data->maps_data->maps_array[i])
	{
		printf("[%s] <%zu>\n", data->maps_data->maps_array[i], ft_strlen(data->maps_data->maps_array[i]));
		i++;
	}
	//to map check

		// color only int DONE
		//possible char and it's limitation DONE
		// while (map[i])
		// {
		// 	while (map[i][j])
		// 	{
		// 		//check char DONE
		// 		/* code */
		// 	}
			
		// 	/* code */
		// }
		
		//surrounded by wall DONE
		//floodfill_check? DONE
		//order of elements DONE
		//space between elements DONE
		//save data (size, 2d array) DONE

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

int	file_reader(t_maps *maps, int fd)
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
	if(ft_check_endl(chdata) == 0)
	{
		//printf("Empty line between map\n");
		free(chdata);
		return (perror("Empty line between map"), 0);
	}
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
