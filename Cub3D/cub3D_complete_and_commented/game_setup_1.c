#include "cub3d.h"

void	game_setup(t_all *a)
{
	resolution_and_tile_size(a);						// Protect the game from inappropriate resolution values ang get tile_size value
	player_initial_position(a);							// Get the player's initial position and orientation
	set_player_speed(a);								// Adjust turn and walk speed based on the resolution
	a->play.size = 7;									// Size of the player to print it in 2d map
	a->aux.num_rays = a->mlx.win_width;					// Calculate number of rays for the raycast depends on horizontal resolution
	a->play.dist_proyection_plane = (a->mlx.win_width / 2) / tan(FOV_ANGLE / 2);	// Get distance from player to proyection plane
	a->mlx.mlx = mlx_init();														// Init the MinilibX and save a pointer to the session
	a->mlx.win = mlx_new_window(a->mlx.mlx, a->mlx.win_width,						// Create new window and save a pointer to it
		 a->mlx.win_height, "Cub3D");
	if (!(a->ray = (t_ray *) malloc(sizeof(t_ray) * a->aux.num_rays)))				// Allocate memory for ray's array
		error_out(a, 1);
	get_wall_textures(a);								// Get data for each wall texture
	get_sprites_textures(a);							// Get data for each sprite texture
	count_sprites(a);									// Count numbers of sprites
	if (!(a->spr = (t_spr *) malloc(sizeof(t_spr) * a->map.spr_count)))				// Allocate memory for sprite's array
		error_out(a, 1);
	get_sprite_data(a);									// Get position (based on the resolution) for each sprite
}

void	resolution_and_tile_size(t_all *a)
{
	float	resolution_ratio;
	float	map_ratio;

	if (a->mlx.win_width > 2560)		// Change the horizontal resolution if it is bigger than the one that device can use
		a->mlx.win_width = 2560;
	if (a->mlx.win_width < 240)			// Change the horiontal resolution if it is too small
		a->mlx.win_width = 240;
	if (a->mlx.win_height > 1440)		// Change the vertical resolution if it is bigger than the one that device can use
		a->mlx.win_height = 1440;
	if (a->mlx.win_height < 240)		// Change the vertical resolution if it is too small
		a->mlx.win_height = 240;
	resolution_ratio = (float)a->mlx.win_width / a->mlx.win_height;		// Get the proportion of vertical and horizontal resolutions
	map_ratio = (float)a->map.max_width / a->map.n_lines;				// Get the proportion of the numbers of columns and rows in the map
	if (resolution_ratio >= map_ratio)									// Use the highest of the two prior ratios to get tile_size
		a->map.tile = a->mlx.win_height / a->map.n_lines;
	else
		a->map.tile = a->mlx.win_width / a->map.max_width;
}

void	player_initial_position(t_all *a)
{
	a->aux.j = 0;
	while (a->aux.j < a->map.n_lines)											// Search for the letter N or S or E or W on the map
	{
		a->aux.i = 0;
		while (a->aux.i++ < a->map.max_width)
		{
			if (a->map.matrix[a->aux.j][a->aux.i] == 'N' || a->map.matrix
				[a->aux.j][a->aux.i] == 'S' || a->map.matrix[a->aux.j]
				[a->aux.i] == 'E' || a->map.matrix[a->aux.j][a->aux.i] == 'W')
			{
				a->play.x = (a->aux.i + 1) * a->map.tile - (a->map.tile / 2); 	// Save player position X
				a->play.y = (a->aux.j + 1) * a->map.tile - (a->map.tile / 2);	// Save player position Y
				if (a->map.matrix[a->aux.j][a->aux.i] == 'N')
					a->play.rotation_angle = PI * 1.5;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'S')				// Set player orientation depends on the letter
					a->play.rotation_angle = PI / 2;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'E')
					a->play.rotation_angle = 0;
				else if (a->map.matrix[a->aux.j][a->aux.i] == 'W')
					a->play.rotation_angle = PI;
				break;
			}
		}
		a->aux.j++;
	}
}

void	set_player_speed(t_all *a)
{
	if (a->mlx.win_width < 800)								// If resolution is small, less speed
	{
		a->play.walk_speed = (float)a->map.tile / 6;
		a->play.turn_speed = 2.0 * (PI / 180);
	}
	else if (a->mlx.win_width > 1600)						// If resolution is big, more speed
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
	else													// If resolution is medium, medium speed
	{
		a->play.walk_speed = (float)a->map.tile / 4;
		a->play.turn_speed = 2.5 * (PI / 180);
	}
}
