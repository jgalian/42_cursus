/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:34:26 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/24 08:14:08 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all	a;

	set_error_messages(&a);
	if (argc != 2 && argc != 3)
		error_out(&a, 0);
	a.aux.i = 0;
	while (argv[1][a.aux.i] != '.')
		a.aux.i++;
	if (ft_strncmp(&argv[1][a.aux.i + 1], "cub", 3) != 0)
		error_out(&a, 18);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0)
		error_out(&a, 17);
	init_variables(&a);
	get_parameters_from_file(&a, argv[1]);
	get_map_matrix(&a, argv[1]);
	validate_map_info(&a);
	game_setup(&a);
	if (a.aux.first_time == TRUE || argc == 3)
		one_time_main_loop(&a, argc);
	mlx_hook(a.mlx.win, 2, 0, &key_press, &a);
	mlx_hook(a.mlx.win, 3, 0, &key_release, &a);
	mlx_hook(a.mlx.win, 17, 0, &exit_game, &a);
	mlx_loop_hook(a.mlx.mlx, &main_loop, &a);
	mlx_loop(a.mlx.mlx);
	return (0);
}

int		one_time_main_loop(t_all *a, int argc)
{
	if (a->play.turn_dir || a->play.walk_dir || a->aux.first_time == TRUE)
	{
		mlx_clear_window(a->mlx.mlx, a->mlx.win);
		a->img.img = mlx_new_image(a->mlx.mlx, a->mlx.win_width,
			a->mlx.win_height);
		a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bits_per_pixel,
			&a->img.line_length, &a->img.endian);
		update(a);
		raycast(a);
		render(a);
	}
	if (argc == 3)
	{
		create_bmp(a);
		exit_game(a);
	}
	mlx_put_image_to_window(a->mlx.mlx, a->mlx.win, a->img.img, 0, 0);
	mlx_destroy_image(a->mlx.mlx, a->img.img);
	return (0);
}

int		main_loop(t_all *a)
{
	if (a->play.turn_dir || a->play.walk_dir || a->aux.first_time == TRUE)
	{
		mlx_clear_window(a->mlx.mlx, a->mlx.win);
		a->img.img = mlx_new_image(a->mlx.mlx, a->mlx.win_width,
			a->mlx.win_height);
		a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bits_per_pixel,
			&a->img.line_length, &a->img.endian);
		update(a);
		raycast(a);
		render(a);
		mlx_put_image_to_window(a->mlx.mlx, a->mlx.win, a->img.img, 0, 0);
		mlx_destroy_image(a->mlx.mlx, a->img.img);
	}
	return (0);
}

int		exit_game(t_all *a)
{
	int		i;

	free(a->ray);
	a->ray = NULL;
	free(a->spr);
	a->spr = NULL;
	i = 0;
	while (i < a->map.n_lines)
	{
		free(a->map.matrix[i]);
		a->map.matrix[i] = NULL;
		i++;
	}
	free(a->map.matrix);
	a->map.matrix = NULL;
	mlx_clear_window(a->mlx.mlx, a->mlx.win);
	mlx_destroy_window(a->mlx.mlx, a->mlx.win);
	write(1, "\n***********************************************\n", 50);
	write(1, "***   You've exited the game successfully   ***\n", 49);
	write(1, "***********************************************\n\n", 50);
	exit(0);
	return (0);
}
