/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_baker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:13:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/03/21 13:43:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

// this function will mallc the new int array according to the each pixel of the png propery

void	copy_tex_prop(mlx_texture_t *m_tex, t_tex *ret)
{
	int	i;
	int	cur_b;
	int	j;

	i = -1;
	cur_b = 0;
	while (++i < m_tex->height)
	{
		j = -1;
		while (++j < m_tex->width)
		{
			ret->tex_pixel[i][j] = get_rgb(m_tex->pixels[cur_b], \
				m_tex->pixels[cur_b + 1], m_tex->pixels[cur_b + 2], \
				m_tex->pixels[cur_b + 3]);
			cur_b += m_tex->bytes_per_pixel;
		}
	}
	ret->width = m_tex->width;
	ret->height = m_tex->height;
}

t_tex	*tex_baker(char *tex_file)
{
	mlx_texture_t	*m_tex;
	t_tex			*ret;
	int				i;

	m_tex = mlx_load_png(tex_file);
	if (m_tex == NULL)
		return (puterror("Texture Cannot load"), NULL);
	ret = ft_calloc(sizeof(t_tex), 1);
	ret->tex_pixel = ft_calloc(sizeof(int *), m_tex->height);
	i = -1;
	while (++i < m_tex->height)
		ret->tex_pixel[i] = ft_calloc(sizeof(int), m_tex->width);
	copy_tex_prop(m_tex, ret);
	mlx_delete_texture(m_tex);
	return (ret);
}
