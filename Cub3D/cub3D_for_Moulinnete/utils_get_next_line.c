/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:35:59 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/23 13:09:26 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_next_line(char **line, int fd)
{
	static char	*gnl;
	char		buff[1025];
	char		*temp;
	int			bt;

	if (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		bt = read(fd, buff, 1024);
		if (bt < 0)
			return (-1);
		else if (!bt)
			break ;
		buff[bt] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = temp;
		}
	}
	return (ft_get_output(line, bt, &gnl));
}

int		ft_get_output(char **line, int bt, char **gnl)
{
	char		*temp;
	char		*temp2;

	if (!bt && !*gnl)
		return (0);
	if ((temp = ft_strchr(*gnl, '\n')))
	{
		*temp = 0;
		*line = ft_strdup(*gnl);
		temp2 = ft_strdup(++temp);
		free(*gnl);
		*gnl = temp2;
	}
	else
	{
		*line = ft_strdup(*gnl);
		free(*gnl);
		*gnl = NULL;
		return (2);
	}
	return (1);
}
