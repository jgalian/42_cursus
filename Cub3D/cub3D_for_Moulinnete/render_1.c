/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:26 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:51:14 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_all *a)
{
	draw_columns(a);
	draw_sprites(a);
	draw_map(a);
	draw_rays(a);
	draw_player(a);
}

void	draw_map(t_all *a)
{
	a->aux.pos_y = 0;
	a->aux.pos_sy = 0;
	a->aux.y = 0;
	while (a->aux.y < a->map.n_lines)
	{
		a->aux.x = 0;
		a->aux.pos_x = 0;
		while (a->aux.x < a->map.max_width)
		{
			a->aux.pos_sx = 0;
			while (a->aux.pos_sx < a->map.tile)
				assign_pixel(a);
			a->aux.x++;
		}
		a->aux.pos_y++;
		a->aux.pos_sy++;
		if (a->aux.pos_sy >= a->map.tile)
		{
			a->aux.y++;
			a->aux.pos_sy = 0;
		}
	}
}

void	draw_rays(t_all *a)
{
	int		id;
	float	i;
	float	new_x;
	float	new_y;

	id = 0;
	while (id < a->aux.num_rays)
	{
		new_x = a->play.x;
		new_y = a->play.y;
		i = 0;
		while (i < a->ray[id].distance)
		{
			new_x += cos(a->ray[id].ray_angle);
			new_y += sin(a->ray[id].ray_angle);
			my_mlx_pixel_put(a, new_x * MINIMAP_SCALE_FACTOR,
				new_y * MINIMAP_SCALE_FACTOR, VERDE);
			i++;
		}
		id++;
	}
}

void	draw_player(t_all *a)
{
	int		i;
	int		j;
	float	x;
	float	y;

	if (a->play.size % 2 == 0)
		a->play.size += 1;
	x = a->play.x - (a->play.size / 2);
	y = a->play.y - (a->play.size / 2);
	j = 0;
	while (j < a->play.size)
	{
		i = 0;
		while (i < a->play.size)
		{
			my_mlx_pixel_put(a, x * MINIMAP_SCALE_FACTOR,
				y * MINIMAP_SCALE_FACTOR, ROJO);
			x++;
			i++;
		}
		y++;
		j++;
		x -= a->play.size;
	}
}
