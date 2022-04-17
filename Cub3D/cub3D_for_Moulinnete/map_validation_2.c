/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:13 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:46:55 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			validate_characters(a, i, j);
			j++;
		}
		i++;
	}
	if (a->map.n_lines < 3 && a->map.max_width < 3)
		error_out(a, 7);
	if (a->map.player_initial_position_exist < 1)
		error_out(a, 6);
	if (a->map.player_initial_position_exist > 1)
		error_out(a, 15);
	if (a->map.zero == 0)
		error_out(a, 7);
}

void	validate_characters(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == '0')
		a->map.zero++;
	else if (a->map.matrix[i][j] == '1' || a->map.matrix[i][j] == '2')
		;
	else if (a->map.matrix[i][j] == 'N' || a->map.matrix[i][j] == 'S'
	|| a->map.matrix[i][j] == 'W' || a->map.matrix[i][j] == 'E')
	{
		a->map.player_initial_position_exist++;
		a->map.player_start_angle = a->map.matrix[i][j];
	}
	else if (a->map.matrix[i][j] == ' ')
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
	else
		error_out(a, 3);
}
