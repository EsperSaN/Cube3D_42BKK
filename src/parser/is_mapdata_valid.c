/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mapdata_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:54:21 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/17 00:57:27 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

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

int is_mapdata_valid(t_data *data)
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