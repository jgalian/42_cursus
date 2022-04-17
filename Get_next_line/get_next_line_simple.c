/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:51:31 by jgalian-          #+#    #+#             */
/*   Updated: 2020/01/27 11:41:49 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **line, char **s)
{
	int			len;
	char		*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		temp = ft_strdup(&(*s)[len + 1]);
		free(*s);
		*s = temp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	get_output(char **line, int char_read, char **s)
{
	if (char_read < 0)
		return (-1);
	else if (char_read == 0 && *s == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_line(line, s));
}

int			get_next_line(int fd, char **line)
{
	int			char_read;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	static char	*s;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while ((char_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[char_read] = '\0';
		if (s == NULL)
			s = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s, buff);
			free(s);
			s = temp;
		}
		if (ft_strchr(s, '\n'))
			break ;
	}
	return (get_output(line, char_read, &s));
}
