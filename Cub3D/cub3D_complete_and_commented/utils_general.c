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
	printf("%s", a->aux.err_message[err_num]);
	exit(-1);
}

void	check_color_values(t_all *a, int r, int g, int b)
{
	if (r < 0 || r > 256 || g < 0 || g > 256 || b < 0 || b > 256)
		error_out(a, 12);
}
