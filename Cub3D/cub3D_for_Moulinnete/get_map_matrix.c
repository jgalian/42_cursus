/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:34:58 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 09:34:59 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_matrix(t_all *a, char *argv)
{
	int i;
	int j;

	a->aux.fd = open(argv, O_RDONLY);
	if (!(a->map.matrix = (char**)malloc(sizeof(char*) * a->map.n_lines)))
		error_out(a, 1);
	i = 0;
	while (i < a->map.n_lines)
	{
		if (!(a->map.matrix[i] = (char *)malloc(a->map.max_width + 1)))
			error_out(a, 1);
		j = 0;
		while (j < a->map.max_width)
		{
			a->map.matrix[i][j] = ' ';
			j++;
		}
		a->map.matrix[i][j] = '\0';
		i++;
	}
	map_to_matrix(a);
	close(a->aux.fd);
}

void	map_to_matrix(t_all *a)
{
	int i;
	int j;

	i = 0;
	while ((get_next_line(&a->aux.line2, a->aux.fd)) > 0)
	{
		j = 0;
		while (a->aux.line2[j] == ' ' || a->aux.line2[j] == '\t')
			j++;
		if (ft_isdigit(a->aux.line2[j]) == TRUE)
		{
			j = 0;
			while (a->aux.line2[j])
			{
				a->map.matrix[i][j] = a->aux.line2[j];
				j++;
			}
			i++;
		}
		ft_free(a->aux.line2);
	}
}
