/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:34:49 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:41:18 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_setup(t_all *a)
{
	resolution_and_tile_size(a);
	player_initial_position(a);
	set_player_speed(a);
	a->play.size = 7;
	a->aux.num_rays = a->mlx.win_width;
	a->play.dist_proyection_plane = (a->mlx.win_width / 2) / tan(FOV_ANGLE / 2);
	a->mlx.mlx = mlx_init();
	a->mlx.win = mlx_new_window(a->mlx.mlx, a->mlx.win_width,
		a->mlx.win_height, "Cub3D");
	if (!(a->ray = (t_ray *)malloc(sizeof(t_ray) * a->aux.num_rays)))
		error_out(a, 1);
	get_wall_textures(a);
	get_sprites_textures(a);
	count_sprites(a);
	if (!(a->spr = (t_spr *)malloc(sizeof(t_spr) * a->map.spr_count)))
		error_out(a, 1);
	get_sprite_data(a);
}

void	resolution_and_tile_size(t_all *a)
{
	float	resolution_ratio;
	float	map_ratio;

	if (a->mlx.win_width > 2560)
		a->mlx.win_width = 2560;
	if (a->mlx.win_width < 240)
		a->mlx.win_width = 240;
	if (a->mlx.win_height > 1440)
		a->mlx.win_height = 1440;
	if (a->mlx.win_height < 240)
		a->mlx.win_height = 240;
	resolution_ratio = (float)a->mlx.win_width / a->mlx.win_height;
	map_ratio = (float)a->map.max_width / a->map.n_lines;
	if (resolution_ratio >= map_ratio)
		a->map.tile = a->mlx.win_height / a->map.n_lines;
	else
		a->map.tile = a->mlx.win_width / a->map.max_width;
}

void	player_initial_position(t_all *a)
{
	a->aux.j = 0;
	while (a->aux.j < a->map.n_lines)
	{
		a->aux.i = 0;
		while (a->aux.i++ < a->map.max_width)
		{
			if (a->map.matrix[a->aux.j][a->aux.i] == 'N' || a->map.matrix
				[a->aux.j][a->aux.i] == 'S' || a->map.matrix[a->aux.j]
				[a->aux.i] == 'E' || a->map.matrix[a->aux.j][a->aux.i] == 'W')
			{
				a->play.x = (a->aux.i + 1) * a->map.tile - (a->map.tile / 2);
				a->play.y = (a->aux.j + 1) * a->map.tile - (a->map.tile / 2);
				if (a->map.matrix[a->aux.j][a->aux.i] == 'N')
					a->play.rotation_angle = PI * 1.5;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'S')
					a->play.rotation_angle = PI / 2;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'E')
					a->play.rotation_angle = 0;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'W')
					a->play.rotation_angle = PI;
				break ;
			}
		}
		a->aux.j++;
	}
}

void	set_player_speed(t_all *a)
{
	if (a->mlx.win_width < 800)
	{
		a->play.walk_speed = (float)a->map.tile / 6;
		a->play.turn_speed = 2.0 * (PI / 180);
	}
	else if (a->mlx.win_width > 1600)
	{
		if (a->mlx.win_height < 800)
		{
			a->play.walk_speed = (float)a->map.tile / 2.5;
			a->play.turn_speed = 3 * (PI / 180);
		}
		else
		{
			a->play.walk_speed = (float)a->map.tile;
			a->play.turn_speed = 4.0 * (PI / 180);
		}
	}
	else
	{
		a->play.walk_speed = (float)a->map.tile / 4;
		a->play.turn_speed = 2.5 * (PI / 180);
	}
}
