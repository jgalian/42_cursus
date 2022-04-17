#include "cub3d.h"

size_t	ft_strlen(char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	pos;

	if (!s || !c)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (&s[pos]);
		pos++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s, char *p)
{
	unsigned int	pos;
	char			*dest;

	if (!(dest = malloc(ft_strlen(s) + ft_strlen(p) + 1)))
		return (NULL);
	pos = 0;
	while (*s)
		dest[pos++] = *s++;
	while (*p)
		dest[pos++] = *p++;
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strdup(char *s)
{
	unsigned int	pos;
	char			*dup;

	if (!(dup = malloc(ft_strlen(s) + 1)))
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		dup[pos] = s[pos];
		pos++;
	}
	dup[pos] = 0;
	return (dup);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
