/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:18 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:35:19 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		raycast(t_all *a)
{
	int		id;

	id = 0;
	a->ray[id].ray_angle = a->play.rotation_angle - (FOV_ANGLE / 2);
	while (id < a->aux.num_rays)
	{
		cast_individual_ray(a, id);
		if (id + 1 < a->aux.num_rays)
			a->ray[id + 1].ray_angle = a->ray[id].ray_angle +
				(FOV_ANGLE / (float)a->mlx.win_width);
		id++;
	}
}

void		cast_individual_ray(t_all *a, int id)
{
	a->ray[id].ray_angle = normalize_angle(a->ray[id].ray_angle);
	ray_facing(a, id);
	horizontal_intersection(a, id);
	vertical_intersection(a, id);
	if (a->ray_aux.found_horz_wall_hit == TRUE &&
		a->ray_aux.found_vert_wall_hit == FALSE)
	{
		a->ray[id].distance = a->ray_aux.horz_hit_dist;
		a->ray[id].was_hit_vertical = FALSE;
		a->ray[id].wall_hit_x = a->ray_aux.horz_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.horz_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.horz_wall_content;
	}
	else if (a->ray_aux.found_horz_wall_hit == FALSE &&
		a->ray_aux.found_vert_wall_hit == TRUE)
	{
		a->ray[id].distance = a->ray_aux.vert_hit_dist;
		a->ray[id].was_hit_vertical = TRUE;
		a->ray[id].wall_hit_x = a->ray_aux.vert_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.vert_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.vert_wall_content;
	}
	else
		check_shortest_hit_distance(a, id);
}

void		check_shortest_hit_distance(t_all *a, int id)
{
	if (a->ray_aux.horz_hit_dist < a->ray_aux.vert_hit_dist)
	{
		a->ray[id].was_hit_vertical = FALSE;
		a->ray[id].distance = a->ray_aux.horz_hit_dist;
		a->ray[id].wall_hit_x = a->ray_aux.horz_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.horz_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.horz_wall_content;
	}
	else
	{
		a->ray[id].distance = a->ray_aux.vert_hit_dist;
		a->ray[id].was_hit_vertical = TRUE;
		a->ray[id].wall_hit_x = a->ray_aux.vert_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.vert_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.vert_wall_content;
	}
}
