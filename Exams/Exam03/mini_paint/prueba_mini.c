#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (1);
}

int	main(int argc, char *argv[])
{
	FILE *fd;
	char **canvas;
	int canvas_width, canvas_height, i, j, ret;
	float x, y, radius, distance;
	char type, background_char, circle_char;

	if (argc != 2)
		ft_error("Error: Argument\n");
	if ((fd = fopen(argv[1], "r")) == NULL)
		ft_error("Error: Operation file corrupted\n");
	if (fscanf(fd, "%d %d %c\n", &canvas_width, &canvas_height, &background_char) != 3)
		ft_error("Error: Operation file corrupted\n");
	if (canvas_width < 1 || canvas_height < 1 || canvas_width > 300 || canvas_height > 300)
		ft_error("Error: Operation file corrupted\n");
	if (!(canvas = (char **)malloc(sizeof(char *) * canvas_height)))
		ft_error("Error: Malloc\n");
	i = 0;
	while (i < canvas_height)
	{
		if (!(canvas[i] = (char *)malloc(canvas_width + 1)))
			ft_error("Error: Malloc\n");
		j = 0;
		while (j < canvas_width)
		{
			canvas[i][j] = background_char;
			j++;
		}
		canvas[i][j] = '\n';
		i++;
	}
	while ((ret = fscanf(fd, "%c %f %f %f %c\n", &type, &x, &y, &radius, &circle_char)) != EOF)
	{
		if (type != 'c' && type != 'C')
			ft_error("Error: Operation file corrupted\n");
		if (radius <= 0)
			ft_error("Error: Operation file corrupted\n");
		i = 0;
		while (i < canvas_height)
		{
			j = 0;
			while (j < canvas_width)
			{
				if ((distance = sqrt((x - j) * (x - j) + (y - i) * (y - i))) <= radius)
				{
					if (type == 'c' && (radius - distance) >= 1)
					{
						j++;
						continue ;
					}
					canvas[i][j] = circle_char;
				}
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < canvas_height)
	{
		j = 0;
		while (j <= canvas_width)
		{
			write(1, &canvas[i][j], 1);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < canvas_height)
	{
		free(canvas[i]);
		canvas[i] = NULL;
		i++;
	}
	free(canvas);
	canvas = NULL;
	fclose(fd);
	return (0);
}
