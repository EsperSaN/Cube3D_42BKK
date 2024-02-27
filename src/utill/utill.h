/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:04:15 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/27 11:21:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILL_H
# define UTILL_H

# include "../cube.h"
# include "./libft/libft.h"

void	puterror(char *error_msg);
int		init_data(t_data *data);
int		init_mlx(t_data *data, int screen_hight, int screen_width);
#endif
