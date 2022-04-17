/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:46 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:58:26 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update(t_all *a)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	a->play.rotation_angle += a->play.turn_dir * a->play.turn_speed;
	move_step = a->play.walk_dir * a->play.walk_speed;
	if (move_step > a->ray[a->mlx.win_width / 2].distance)
		move_step = a->ray[a->mlx.win_width / 2].distance - 5;
	new_player_x = a->play.x + cos(a->play.rotation_angle +
		a->play.lateral_mov) * move_step;
	new_player_y = a->play.y + sin(a->play.rotation_angle +
		a->play.lateral_mov) * move_step;
	check_new_position(a, new_player_x, new_player_y);
	update_sprites(a);
	sort_sprites(a);
}

void	check_new_position(t_all *a, float new_x, float new_y)
{
	int		new_map_x;
	int		new_map_y;
	int		map[2];

	map[0] = get_map_position(a, a->play.x);
	map[1] = get_map_position(a, a->play.y);
	new_map_x = get_map_position(a, new_x);
	new_map_y = get_map_position(a, new_y);
	if (new_map_x != map[0] && new_map_y != map[1])
	{
		if (is_new_position_ok(a, new_map_x, new_map_y, map) ==
			TRUE && wall_check(a, new_x, new_y) != 1)
		{
			a->play.x = new_x;
			a->play.y = new_y;
		}
	}
	else if (wall_check(a, new_x, new_y) != 1)
	{
		a->play.x = new_x;
		a->play.y = new_y;
	}
}

int		get_map_position(t_all *a, float f)
{
	int		map_position;

	map_position = floor(f / a->map.tile);
	return (map_position);
}

int		is_new_position_ok(t_all *a, float new_map_x,
	float new_map_y, int map[])
{
	if (new_map_x > map[0] && new_map_y < map[1])
	{
		if (a->map.matrix[map[1]][map[0] + 1] == '1' &&
			a->map.matrix[map[1] - 1][map[0]] == '1')
			return (FALSE);
	}
	else if (new_map_x > map[0] && new_map_y > map[1])
	{
		if (a->map.matrix[map[1]][map[0] + 1] == '1' &&
			a->map.matrix[map[1] + 1][map[0]] == '1')
			return (FALSE);
	}
	else if (new_map_x < map[0] && new_map_y > map[1])
	{
		if (a->map.matrix[map[1]][map[0] - 1] == '1' &&
			a->map.matrix[map[1] + 1][map[0]] == '1')
			return (FALSE);
	}
	else if (new_map_x < map[0] && new_map_y < map[1])
	{
		if (a->map.matrix[map[1]][map[0] - 1] == '1' &&
			a->map.matrix[map[1] - 1][map[0]] == '1')
			return (FALSE);
	}
	return (TRUE);
}
