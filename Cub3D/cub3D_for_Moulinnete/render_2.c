/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:30 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:35:31 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_columns(t_all *a)
{
	int				i;
	float			proyected_wall_height;
	float			perp_distance;
	int				w_top_pix;
	int				w_bot_pix;

	w_top_pix = 0;
	w_bot_pix = 0;
	i = 0;
	while (i < a->aux.num_rays)
	{
		perp_distance = a->ray[i].distance * cos(a->ray[i].ray_angle -
			a->play.rotation_angle);
		proyected_wall_height = (a->map.tile / perp_distance) *
			a->play.dist_proyection_plane;
		a->ray_aux.w_strip_height = (int)proyected_wall_height;
		w_top_pix = (a->mlx.win_height / 2) - (a->ray_aux.w_strip_height / 2);
		w_top_pix = w_top_pix < 0 ? 0 : w_top_pix;
		w_bot_pix = (a->mlx.win_height / 2) + (a->ray_aux.w_strip_height / 2);
		w_bot_pix = w_bot_pix > (int)a->mlx.win_height ?
			a->mlx.win_height : w_bot_pix;
		draw_ceiling_and_floor(a, i, w_top_pix, w_bot_pix);
		draw_walls(a, i, w_top_pix, w_bot_pix);
		i++;
	}
}

void			draw_ceiling_and_floor(t_all *a, int i, float w_top_pix,
	float w_bot_pix)
{
	int		y;

	y = 0;
	while (y < w_top_pix)
	{
		my_mlx_pixel_put(a, i, y, a->param.c_color);
		y++;
	}
	y = w_bot_pix;
	while (y < (int)a->mlx.win_height)
	{
		my_mlx_pixel_put(a, i, y, a->param.f_color);
		y++;
	}
}

void			draw_walls(t_all *a, int i, float w_top_pix, float w_bot_pix)
{
	int				y;
	int				texture_offset_x;
	int				texture_offset_y;
	int				distance_from_top;
	unsigned int	texel_color;

	if (a->ray[i].was_hit_vertical)
		texture_offset_x = (((int)a->ray[i].wall_hit_y % a->map.tile)
			* ((float)a->text[0].width / a->map.tile));
	else
		texture_offset_x = (((int)a->ray[i].wall_hit_x % a->map.tile)
			* ((float)a->text[0].width / a->map.tile));
	y = w_top_pix;
	while (y < w_bot_pix)
	{
		distance_from_top = y + (a->ray_aux.w_strip_height / 2)
			- (a->mlx.win_height / 2);
		texture_offset_y = distance_from_top * ((float)a->text[0].height
			/ a->ray_aux.w_strip_height);
		texel_color = get_color_from_texture(a, i, texture_offset_x,
			texture_offset_y);
		my_mlx_pixel_put(a, i, y, texel_color);
		y++;
	}
}

unsigned int	get_color_from_texture(t_all *a, int i, int texture_offset_x,
	int texture_offset_y)
{
	char			*dst;
	unsigned int	texel_color;

	if (a->ray[i].was_hit_vertical)
	{
		if (a->ray[i].is_ray_facing_l == TRUE)
			dst = a->text[1].addr + (texture_offset_y * a->text[1].line_length
				+ texture_offset_x * (a->text[1].bits_per_pixel / 8));
		else
			dst = a->text[3].addr + (texture_offset_y * a->text[3].line_length
				+ texture_offset_x * (a->text[3].bits_per_pixel / 8));
	}
	else
	{
		if (a->ray[i].is_ray_facing_u == TRUE)
			dst = a->text[2].addr + (texture_offset_y * a->text[2].line_length
				+ texture_offset_x * (a->text[2].bits_per_pixel / 8));
		else
			dst = a->text[0].addr + (texture_offset_y * a->text[0].line_length
				+ texture_offset_x * (a->text[0].bits_per_pixel / 8));
	}
	texel_color = *(unsigned int*)dst;
	return (texel_color);
}
