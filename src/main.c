/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:38:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/01/31 15:18:24 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#define INVALID_ARG "No argument supplied"
#define INVALID_FILE "The given file must contain .cub extention"

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || av[1] == NULL)
		return (puterror(INVALID_ARG), 1);
	if (!is_right_extention(av[1]))
		return (puterror(INVALID_FILE), 2);
	printf("HELLO CUBE\n");
}
