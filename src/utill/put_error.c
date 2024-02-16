/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:12 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/15 17:39:07 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utill.h"

void	puterror(char *error_msg);

void	puterror(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	return ;
}
