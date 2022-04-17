/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:36:07 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:59:45 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_pixel(t_all *a)
{
	if (a->map.matrix[a->aux.y][a->aux.x] == '1' ||
		a->map.matrix[a->aux.y][a->aux.x] == ' ')
		my_mlx_pixel_put(a, a->aux.pos_x * MINIMAP_SCALE_FACTOR,
			a->aux.pos_y * MINIMAP_SCALE_FACTOR, NEGRO);
	else if (a->map.matrix[a->aux.y][a->aux.x] == '0')
		my_mlx_pixel_put(a, a->aux.pos_x * MINIMAP_SCALE_FACTOR,
			a->aux.pos_y * MINIMAP_SCALE_FACTOR, BLANCO);
	else if (a->map.matrix[a->aux.y][a->aux.x] == '2')
		my_mlx_pixel_put(a, a->aux.pos_x * MINIMAP_SCALE_FACTOR,
			a->aux.pos_y * MINIMAP_SCALE_FACTOR, GRIS_CLARO);
	else
		my_mlx_pixel_put(a, a->aux.pos_x * MINIMAP_SCALE_FACTOR,
			a->aux.pos_y * MINIMAP_SCALE_FACTOR, BLANCO);
	a->aux.pos_sx++;
	a->aux.pos_x++;
}

void	my_mlx_pixel_put(t_all *a, int x, int y, int color)
{
	char	*dst;

	dst = a->img.addr + (y * a->img.line_length + x *
		(a->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
