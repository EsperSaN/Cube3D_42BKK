/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:52:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/17 01:14:11 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

int	ft_check_endl(char *str)
{
	int		i;
	int		j;
	int		len;
	int		flag;
	char	*tmp;

	flag = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			len = i - j - 1;
			if (len < 0)
				len = 0;
			tmp = ft_substr(str, j, len);
			//printf("[%s]\n", tmp);
			if (ft_is_map(tmp) && len > 0)
				flag = 1;
			//printf("%d %d\n", len, flag);
			if (len == 0 && flag)
				return (0);
			j = i + 1;
			free(tmp);
		}
		i++;
	}
	return (1);
}

int	file_reader(t_data *data, int fd)
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
	if (ft_check_endl(chdata) == 0)
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
