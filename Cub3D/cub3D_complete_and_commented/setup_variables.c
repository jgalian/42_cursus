#include "cub3d.h"

void	init_variables(t_all *a)
{
	a->mlx.win_width = 0;
	a->mlx.win_height = 0;
	a->map.n_lines = 0;
	a->aux.line = NULL;
	a->aux.r = 0;
	a->aux.g = 0;
	a->aux.b = 0;
	a->map.zero = 0;
	a->map.player_initial_position_exist = 0;
	a->map.player_start_angle = ' ';
	a->map.max_width = 0;
	a->play.turn_dir = 0;
	a->play.walk_dir = 0;
	a->play.lateral_mov = 0;
	a->aux.first_time = TRUE;
}

void	reset_r_g_b(t_all *a)
{
	a->aux.r = 0;
	a->aux.g = 0;
	a->aux.b = 0;
}

void	set_error_messages(t_all *a)
{
	a->aux.err_message[0] = "Error: Invalid number of arguments\n";
	a->aux.err_message[1] = "Error: Unable to reserve memory\n";
	a->aux.err_message[2] = "Error: Invalid resolution\n";
	a->aux.err_message[3] = "Error: Invalid map characters\n";
	a->aux.err_message[4] = "Error: Unable to open texture file\n";
	a->aux.err_message[5] = "Error: Map isn't surrounded by walls\n";
	a->aux.err_message[6] = "Error: Should be at least one player on the map\n";
	a->aux.err_message[7] = "Error: No empty space in map\n";
	a->aux.err_message[8] = "Error: Missing texture\n";
	a->aux.err_message[9] = "Error: Missing floor or ceiling color\n";
	a->aux.err_message[10] =
		"Error: Floor and ceiling color should be different\n";
	a->aux.err_message[11] =
		"Error: Resolution values should be between 420 and 1920\n";
	a->aux.err_message[12] =
		"Error: Color values should be between 0 and 256\n";
	a->aux.err_message[13] = "Error: Invalid space character inside map\n";
	a->aux.err_message[14] = "Error: Invalid number of arguments\n";
	a->aux.err_message[15] = "Error: Should be only one player on the map\n";
	a->aux.err_message[16] = "Error: Map should be at the end of the file\n";
	a->aux.err_message[17] = "Error: Invalid parameter passed to the game\n";
	a->aux.err_message[18] = "Error: First argument shoul be '.cub' file\n";
}
