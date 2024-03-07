/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:54:48 by pruenrua          #+#    #+#             */
/*   Updated: 2024/02/29 15:54:47 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
#define CONTROL_H

# include "../cube.h"

#define KEYPRESSMASK 1L<<0
#define KEYRELEASEMASK 1L<<1
#define NOEVENTMASK 0L
#define BUTTONRELEASEMASK 1L<<3
#define ON_KEYDOWN 2
#define ON_KEYUP 3
#define ON_DESTROY 17
#define RELEASE 0
#define PRESS 1

int control(t_data *data);
#endif