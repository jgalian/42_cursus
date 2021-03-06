/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:23:13 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/09 08:35:01 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char*)malloc(ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str3 = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str3[i] = s2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sub;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (str == NULL)
		return (NULL);
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (str[i] != '\0' && i < len)
		{
			sub[i] = str[i + start];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

void	reverse_str(char **str)
{
	int		str_len;
	char	*temp;
	int		i;

	str_len = ft_strlen(*str);
	i = 0;
	temp = (char *)malloc(str_len + 1);
	while (str_len > 0)
		temp[i++] = (*str)[--str_len];
	temp[i] = '\0';
	free(*str);
	*str = temp;
}
