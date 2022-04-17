/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:42 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 11:04:01 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_sprites(t_all *a)
{
	int			id;
	float		vectors_angle;

	id = 0;
	while (id < a->map.spr_count)
	{
		a->spr[id].vector_x = a->spr[id].spr_x - a->play.x;
		a->spr[id].vector_y = a->spr[id].spr_y - a->play.y;
		vectors_angle = atan2(a->spr[id].vector_y, a->spr[id].vector_x);
		a->spr[id].spr_play_angle = vectors_angle - a->play.rotation_angle;
		if (a->spr[id].spr_play_angle < (-1 * PI))
			a->spr[id].spr_play_angle += 2.0 * PI;
		if (a->spr[id].spr_play_angle > PI)
			a->spr[id].spr_play_angle -= 2.0 * PI;
		a->spr[id].spr_play_angle_abs = fabs(a->spr[id].spr_play_angle);
		if (a->spr[id].spr_play_angle >= -0.57735 && a->spr[id].
			spr_play_angle <= 0.57735)
			a->spr[id].visible = TRUE;
		else
			a->spr[id].visible = FALSE;
		a->spr[id].spr_play_distance = dist_between_points(a->play.x,
			a->play.y, a->spr[id].spr_x, a->spr[id].spr_y);
		get_spr_render_start_point(a, id);
		id++;
	}
}

void	get_spr_render_start_point(t_all *a, int id)
{
	float	aux_x;
	float	tangent;

	a->spr[id].height = (a->map.tile / a->spr[id].spr_play_distance)
		* a->play.dist_proyection_plane;
	a->spr[id].start_render_y = (a->mlx.win_height / 2) -
		(a->spr[id].height / 2);
	a->spr[id].end_render_y = a->spr[id].start_render_y + a->spr[id].height;
	tangent = tan(a->spr[id].spr_play_angle);
	aux_x = tangent * a->play.dist_proyection_plane;
	a->spr[id].start_render_x = (a->mlx.win_width / 2 + aux_x) -
		(a->spr[id].height / 2);
	a->spr[id].end_render_x = a->spr[id].start_render_x + a->spr[id].height;
}

void	sort_sprites(t_all *a)
{
	int		id;

	id = 0;
	while (id < a->map.spr_count - 1)
	{
		if (a->spr[id].spr_play_distance < a->spr[id + 1].spr_play_distance)
		{
			ft_swap(&a->spr[id], &a->spr[id + 1]);
			id = -1;
		}
		id++;
	}
}

void	ft_swap(t_spr *spr1, t_spr *spr2)
{
	t_spr	spr3;

	spr3 = *spr1;
	*spr1 = *spr2;
	*spr2 = spr3;
}
