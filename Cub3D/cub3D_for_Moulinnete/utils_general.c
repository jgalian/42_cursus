/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:55 by jgalian-          #+#    #+#             */
/*   Updated: 2020/10/27 11:35:45 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

void	skip_spaces(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
	|| (s[i] == '\r' || s[i] == '\v' || s[i] == '\f'))
		i++;
}

int		error_out(t_all *a, int err_num)
{
	write(1, a->aux.err_message[err_num],
		ft_strlen(a->aux.err_message[err_num]));
	exit(-1);
}

void	check_color_values(t_all *a, int r, int g, int b)
{
	if (r < 0 || r > 256 || g < 0 || g > 256 || b < 0 || b > 256)
		error_out(a, 12);
}
