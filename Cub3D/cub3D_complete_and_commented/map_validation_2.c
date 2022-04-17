#include "cub3d.h"

void	validate_characters(t_all *a, int i, int j);

void	other_map_validations(t_all *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->map.n_lines)
	{
		j = 0;
		while (j < a->map.max_width)
		{
			validate_characters(a, i, j);									// Check there is no forbidden characters
			j++;
		}
		i++;
	}
	if (a->map.n_lines < 3 && a->map.max_width < 3)							// Check if there is enough space for player to move in the map
		error_out(a, 7);
	if (a->map.player_initial_position_exist < 1)							// Check is there is one player in the map
		error_out(a, 6);
	if (a->map.player_initial_position_exist > 1)							// Check is there is no more than one player in the map
		error_out(a, 15);
	if (a->map.zero == 0)													// Check if there is enough space for player to move in the map
		error_out(a, 7);
}

void	validate_characters(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == '0')											// Count the empty spaces in the map for player to move
		a->map.zero++;
	else if (a->map.matrix[i][j] == '1' || a->map.matrix[i][j] == '2')		// Skip walls and sprites
		;
	else if (a->map.matrix[i][j] == 'N' || a->map.matrix[i][j] == 'S'		// Check player position and save his orientation
	|| a->map.matrix[i][j] == 'W' || a->map.matrix[i][j] == 'E')
	{
		a->map.player_initial_position_exist++;
		a->map.player_start_angle = a->map.matrix[i][j];
	}
	else if (a->map.matrix[i][j] == ' ')									// Check for invalid spaces inside the map
	{
		if ((j - 1 >= 0 && a->map.matrix[i][j - 1] != '1'
			&& a->map.matrix[i][j - 1] != ' ')
			|| (j + 1 <= a->map.max_width - 1 && a->map.matrix[i][j + 1] != '1'
			&& a->map.matrix[i][j + 1] != ' ')
			|| (i - 1 >= 0 && a->map.matrix[i - 1][j] != '1'
			&& a->map.matrix[i - 1][j] != ' ')
			|| (i + 1 <= a->map.n_lines - 1 && a->map.matrix[i + 1][j] != '1'
			&& a->map.matrix[i + 1][j] != ' '))
		error_out(a, 13);
	}
	else																	// If character is not '0', '1', '2', 'N', 'S', 'E', 'W' or ' '...
		error_out(a, 3);													// ...send error message
}

