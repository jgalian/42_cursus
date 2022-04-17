#include "libft.h"

int	ft_getchar(void)
{
	char	buf[1];
	int		c;
	int		bytes_read;

	bytes_read = read(0, &buf, 1);
	if (bytes_read == -1)
		return (EOF);
	c = (int)buf[0];
	return (c);
}
