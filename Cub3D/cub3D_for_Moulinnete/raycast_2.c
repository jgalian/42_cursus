/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:22 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:50:37 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection(t_all *a, int id)
{
	float	xintercept;
	float	yintercept;

	a->ray_aux.horz_wall_hit_x = 0;
	a->ray_aux.horz_wall_hit_y = 0;
	a->ray_aux.horz_wall_content = 0;
	yintercept = floor(a->play.y / a->map.tile) * a->map.tile;
	yintercept += a->ray[id].is_ray_facing_d ? a->map.tile : 0;
	xintercept = a->play.x + (yintercept - a->play.y) /
		tan(a->ray[id].ray_angle);
	a->ray_aux.horz_ystep = a->map.tile;
	a->ray_aux.horz_ystep *= a->ray[id].is_ray_facing_u ? -1 : 1;
	a->ray_aux.horz_xstep = a->map.tile / tan(a->ray[id].ray_angle);
	a->ray_aux.horz_xstep *= (a->ray[id].is_ray_facing_l &&
		a->ray_aux.horz_xstep > 0) ? -1 : 1;
	a->ray_aux.horz_xstep *= (a->ray[id].is_ray_facing_r &&
		a->ray_aux.horz_xstep < 0) ? -1 : 1;
	check_horizontal_collision(a, xintercept, yintercept, id);
}

void	check_horizontal_collision(t_all *a, float xintercept,
	float yintercept, int id)
{
	float	next_horz_touch_x;
	float	next_horz_touch_y;

	a->ray_aux.found_horz_wall_hit = FALSE;
	next_horz_touch_x = xintercept;
	next_horz_touch_y = yintercept;
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= a->mlx.win_width
		&& next_horz_touch_y >= 0 && next_horz_touch_y <= a->mlx.win_height)
	{
		a->ray_aux.x_to_check = next_horz_touch_x;
		a->ray_aux.y_to_check = next_horz_touch_y +
			(a->ray[id].is_ray_facing_u ? -1 : 0);
		if (wall_check(a, a->ray_aux.x_to_check, a->ray_aux.y_to_check) == 1)
		{
			a->ray_aux.horz_wall_hit_x = next_horz_touch_x;
			a->ray_aux.horz_wall_hit_y = next_horz_touch_y;
			a->ray_aux.horz_wall_content = 1;
			a->ray_aux.found_horz_wall_hit = TRUE;
			a->ray_aux.horz_hit_dist = dist_between_points(a->play.x, a->
				play.y, a->ray_aux.horz_wall_hit_x, a->ray_aux.horz_wall_hit_y);
			break ;
		}
		next_horz_touch_x += a->ray_aux.horz_xstep;
		next_horz_touch_y += a->ray_aux.horz_ystep;
	}
}

void	vertical_intersection(t_all *a, int id)
{
	float	xintercept;
	float	yintercept;

	a->ray_aux.vert_wall_hit_x = 0;
	a->ray_aux.vert_wall_hit_y = 0;
	a->ray_aux.vert_wall_content = 0;
	xintercept = floor(a->play.x / a->map.tile) * a->map.tile;
	xintercept += a->ray[id].is_ray_facing_r ? a->map.tile : 0;
	yintercept = a->play.y + (xintercept - a->play.x)
		* tan(a->ray[id].ray_angle);
	a->ray_aux.vert_xstep = a->map.tile;
	a->ray_aux.vert_xstep *= a->ray[id].is_ray_facing_l ? -1 : 1;
	a->ray_aux.vert_ystep = a->map.tile * tan(a->ray[id].ray_angle);
	a->ray_aux.vert_ystep *= (a->ray[id].is_ray_facing_u &&
		a->ray_aux.vert_ystep > 0) ? -1 : 1;
	a->ray_aux.vert_ystep *= (a->ray[id].is_ray_facing_d &&
		a->ray_aux.vert_ystep < 0) ? -1 : 1;
	check_vertical_collision(a, xintercept, yintercept, id);
}

void	check_vertical_collision(t_all *a, float xintercept,
	float yintercept, int id)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	a->ray_aux.found_vert_wall_hit = FALSE;
	next_vert_touch_x = xintercept;
	next_vert_touch_y = yintercept;
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= a->mlx.win_width
		&& next_vert_touch_y >= 0 && next_vert_touch_y <= a->mlx.win_height)
	{
		a->ray_aux.x_to_check = next_vert_touch_x +
			(a->ray[id].is_ray_facing_l ? -1 : 0);
		a->ray_aux.y_to_check = next_vert_touch_y;
		if (wall_check(a, a->ray_aux.x_to_check, a->ray_aux.y_to_check) == 1)
		{
			a->ray_aux.vert_wall_hit_x = next_vert_touch_x;
			a->ray_aux.vert_wall_hit_y = next_vert_touch_y;
			a->ray_aux.vert_wall_content = 1;
			a->ray_aux.found_vert_wall_hit = TRUE;
			a->ray_aux.vert_hit_dist = dist_between_points(a->play.x, a->play.y,
				a->ray_aux.vert_wall_hit_x, a->ray_aux.vert_wall_hit_y);
			break ;
		}
		next_vert_touch_x += a->ray_aux.vert_xstep;
		next_vert_touch_y += a->ray_aux.vert_ystep;
	}
}
