#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all	a;

	set_error_messages(&a);													// Function that contained all error messages
	if (argc != 2 && argc != 3)												// Check we have two or three parameters
		error_out(&a, 0);
	a.aux.i = 0;
	while (argv[1][a.aux.i] != '.')
		a.aux.i++;
	if (ft_strncmp(&argv[1][a.aux.i + 1], "cub", 3) != 0)
		error_out(&a, 18);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0)
		error_out(&a, 17);
	init_variables(&a);
	get_parameters_from_file(&a, argv[1]);									// Function to asign validation tasks
	get_map_matrix(&a, argv[1]);											// Parse map from file to a variable
	validate_map_info(&a);													// Check for not allowed stuff and errors
	game_setup(&a);															// Setup the initial configurations
	if (a.aux.first_time == TRUE || argc == 3)								// If it is the first time or the argument '--save' has been passed...
		one_time_main_loop(&a, argc);										// ... execute special one time main_loop
	mlx_hook(a.mlx.win, 2, 0, &key_press, &a);
	mlx_hook(a.mlx.win, 3, 0, &key_release, &a);
	mlx_hook(a.mlx.win, 17, 0, &exit_game, &a);
	mlx_loop_hook(a.mlx.mlx, &main_loop, &a);								// Infinite loop to the main_loop
	mlx_loop(a.mlx.mlx);
	return (0);
}

int		one_time_main_loop(t_all *a, int argc)
{
	if (a->play.turn_dir || a->play.walk_dir || a->aux.first_time == TRUE)  // Only update frame if it is the first time...
	{																		// ...or something have changed
		mlx_clear_window(a->mlx.mlx, a->mlx.win);							// Clean the window (all black)
		a->img.img = mlx_new_image(a->mlx.mlx, a->mlx.win_width,
			a->mlx.win_height);												// Create a new image
		a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bits_per_pixel,	// Get data for the new image
			&a->img.line_length, &a->img.endian);
		update(a);															// Update all elements in the game
		raycast(a);															// Get the new data for each ray (angle, distance, direction...)
		render(a);															// Use the updated data to draw view, map, player, sprites...
	}
	if (argc == 3)
	{
		create_bmp(a);
		exit_game(a);
	}
	mlx_put_image_to_window(a->mlx.mlx, a->mlx.win, a->img.img, 0, 0);		// Launch the image from the buffer to the screen
	mlx_destroy_image(a->mlx.mlx, a->img.img);								// Destroy image buffer
	return (0);
}

int		main_loop(t_all *a)
{
	if (a->play.turn_dir || a->play.walk_dir || a->aux.first_time == TRUE)  // Only update frame if it is the first time...
	{																		// ...or something have changed
		mlx_clear_window(a->mlx.mlx, a->mlx.win);							// Clean the window (all black)
		a->img.img = mlx_new_image(a->mlx.mlx, a->mlx.win_width,
			a->mlx.win_height);												// Create a new image
		a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bits_per_pixel,				// Get data for the new image
			&a->img.line_length, &a->img.endian);
		update(a);															// Update all elements in the game
		raycast(a);															// Get the new data for each ray (angle, distance, direction...)
		render(a);															// Use the updated data to draw view, map, player, sprites...
		mlx_put_image_to_window(a->mlx.mlx, a->mlx.win, a->img.img, 0, 0);	// Launch the image from the buffer to the screen
		mlx_destroy_image(a->mlx.mlx, a->img.img);							// Destroy image buffer
	}
	return (0);
}

int		exit_game(t_all *a)
{
	int		i;

	free(a->ray);															// Free alllocated memory for the ray's array
	a->ray = NULL;
	free(a->spr);															// Free allocated memory for the sprite's array
	a->spr = NULL;
	i = 0;
	while (i < a->map.n_lines)
	{
		free(a->map.matrix[i]);												// Free allocated memory for map matrix
		a->map.matrix[i] = NULL;
		i++;
	}
	free(a->map.matrix);
	a->map.matrix = NULL;
	mlx_clear_window(a->mlx.mlx, a->mlx.win);
	mlx_destroy_window(a->mlx.mlx, a->mlx.win);
	write(1, "\n***********************************************\n", 50);	// Game exit message
	write(1, "***   You've exited the game successfully   ***\n", 49);
	write(1, "***********************************************\n\n", 50);
	system("leaks cub3D");													// Check for leaks
	exit(0);																// Exits the game
	return(0);
}
