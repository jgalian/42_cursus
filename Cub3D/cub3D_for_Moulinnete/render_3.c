/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:34 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:51:45 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_all *a)
{
	int		id;

	id = 0;
	while (id < a->map.spr_count)
	{
		if (a->spr[id].visible == TRUE)
			draw_sprite(a, id);
		id++;
	}
}

void	draw_sprite(t_all *a, int id)
{
	int				x;
	int				y;

	a->aux.step = (float)a->spr_text[0].width / (float)a->spr[id].height;
	a->aux.pos_x_text = 0;
	x = a->spr[id].start_render_x;
	while (x < a->spr[id].end_render_x)
	{
		if (x >= 0 && x < (int)a->mlx.win_width && a->spr[id].spr_play_distance
			< a->ray[x].distance)
		{
			a->aux.pos_y_text = 0;
			y = (int)a->spr[id].start_render_y;
			while (y < (int)a->spr[id].end_render_y)
			{
				if (y > 0 && y < (int)a->mlx.win_height)
					get_sprite_color_from_texture(a, x, y);
				y++;
				a->aux.pos_y_text += a->aux.step;
			}
		}
		x++;
		a->aux.pos_x_text += a->aux.step;
	}
}

void	get_sprite_color_from_texture(t_all *a, int x, int y)
{
	char			*dst;
	unsigned int	texel_color;

	dst = a->spr_text[0].addr + ((int)a->aux.pos_y_text *
		a->spr_text[0].line_length + (int)a->aux.pos_x_text *
		(a->spr_text[0].bits_per_pixel / 8));
	texel_color = *(unsigned int*)dst;
	if (texel_color != NEGRO)
		my_mlx_pixel_put(a, x, y, texel_color);
}
