/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:09 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:45:33 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map_info(t_all *a)
{
	validate_parameters(a);
	validate_map_horizontal_limits(a);
	validate_map_vertical_limits(a);
	other_map_validations(a);
}

void	validate_parameters(t_all *a)
{
	if (!a->mlx.win_width || !a->mlx.win_height)
		error_out(a, 2);
	if (!a->param.text_no || !a->param.text_so || !a->param.text_ea ||
		!a->param.text_we || !a->param.text_spr)
		error_out(a, 8);
	else
		validate_textures(a);
	if (a->aux.r < 0 || a->aux.r > 256 || a->aux.g < 0 || a->aux.g > 256
		|| a->aux.b < 0 || a->aux.b > 256)
		error_out(a, 12);
	if (!a->param.f_color || !a->param.c_color)
		error_out(a, 9);
	if (a->param.f_color == a->param.c_color)
		error_out(a, 10);
}

void	validate_textures(t_all *a)
{
	int fd;

	if ((fd = open(WALL_1_PATH, O_RDONLY)) < 0)
		error_out(a, 4);
	else
		close(fd);
	if ((fd = open(WALL_2_PATH, O_RDONLY)) < 0)
		error_out(a, 4);
	else
		close(fd);
	if ((fd = open(WALL_3_PATH, O_RDONLY)) < 0)
		error_out(a, 4);
	else
		close(fd);
	if ((fd = open(WALL_4_PATH, O_RDONLY)) < 0)
		error_out(a, 4);
	else
		close(fd);
	if ((fd = open(SPR_1_PATH, O_RDONLY)) < 0)
		error_out(a, 4);
	else
		close(fd);
}

void	validate_map_horizontal_limits(t_all *a)
{
	int	i;
	int j;

	i = 0;
	while (i < a->map.n_lines)
	{
		j = 0;
		while (a->map.matrix[i][j] == ' ')
			j++;
		if (a->map.matrix[i][j] != '1')
			error_out(a, 5);
		else
			i++;
	}
	i = 0;
	while (i < a->map.n_lines)
	{
		j = a->map.max_width - 1;
		while (a->map.matrix[i][j] == ' ')
			j--;
		if (a->map.matrix[i][j] != '1')
			error_out(a, 5);
		else
			i++;
	}
}

void	validate_map_vertical_limits(t_all *a)
{
	int	i;
	int j;

	j = 0;
	while (j < a->map.max_width)
	{
		i = 0;
		while (a->map.matrix[i][j] == ' ')
			i++;
		if (a->map.matrix[i][j] != '1')
			error_out(a, 5);
		else
			j++;
	}
	j = 0;
	while (j < a->map.max_width)
	{
		i = a->map.n_lines - 1;
		while (a->map.matrix[i][j] == ' ')
			i--;
		if (a->map.matrix[i][j] != '1')
			error_out(a, 5);
		else
			j++;
	}
}
