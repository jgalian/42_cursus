#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int		main(int argc, char **argv)
{
	FILE	*fd;
	char	**canvas;
	float	xf, yf, x2f, y2f, rect_width_f, rect_height_f;
	int		canvas_width, canvas_height, xi, yi, x2i, y2i, i, j, ret;
	char	type, background_char, fill_char;

	// CONTROL DE ARGUMENTOS
	if (argc != 2)
		ft_error("Error: argument\n");

	// OPEN FILE
	if ((fd = fopen(argv[1], "r")) == NULL)
		ft_error("Error: Operation file corrupted\n");

	// READING FIRST LINE IN ORDER TO KNOW CANVAS SIZE AND BACKGROUND CHARACTER
	if (fscanf(fd, "%i %i %c\n", &canvas_width, &canvas_height, &background_char) != 3)
		ft_error("Error: Operation file corrupted\n");

	// CHECK FOR ERRORS IN CANVAS SIZE
	if (canvas_width < 1 || canvas_height < 1 || canvas_width > 300 || canvas_height > 300)
		ft_error("Error: Operation file corrupted\n");

	// MEMORY ALLOCATION FOR CANVAS
	if (!(canvas = (char **)malloc(sizeof(char *) * canvas_height)))
		ft_error("Error: malloc\n");
	i = 0;
	while (i < canvas_height)
	{
		if (!(canvas[i] = (char *)malloc(canvas_width + 1)))
			ft_error("Error: malloc\n");
		j = 0;									//
		while (j < canvas_width)				//
		{										//
			canvas[i][j] = background_char;		// RENDERING CANVAS
			j++;								//
		}										//
		canvas[i][j] = '\n';					//
		i++;
	}

	// READING AND RENDERING FILLED RECTANGLES
	while ((ret = fscanf(fd, "%c %f %f %f %f %c\n", &type, &xf, &yf, &rect_width_f, &rect_height_f, &fill_char)) != EOF)
	{
		if (ret != 6)
			ft_error("Error: Operation file corrupted\n");
		if (type != 'r' && type != 'R')
			ft_error("Error: Operation file corrupted\n");
		if (rect_width_f <= 0 || rect_height_f <= 0)
			ft_error("Error: Operation file corrupted\n");
		x2f = xf + rect_width_f;
		y2f = yf + rect_height_f;
		xi = (xf > (int)xf) ? (int)xf + 1 : (int)xf;
		yi = (yf > (int)yf) ? (int)yf + 1 : (int)yf;
		x2i = (x2f < 0 && x2f > -1) ? -1 : (int)x2f;
		y2i = (y2f < 0 && y2f > -1) ? -1 : (int)y2f;
		//x2i = (int)x2f;
		//y2i = (int)y2f;
		i = 0;
		while (i < canvas_height)
		{
			j = 0;
			while (j < canvas_width)
			{
				if ((int)xi <= j && j <= x2i && (int)yi <= i && i <= y2i)
				{
					if (type == 'r' && (int)xi != j && j != x2i && (int)yi != i && i != y2i)
					{
						j++;
						continue ;
					}
					canvas[i][j] = fill_char;
				}
				j++;
			}
			i++;
		}
	}

	// DRAWING FINAL IMAGE
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
	//write(1, "\n", 1);

	// SETTING FREE ALLOCATED MEMORY AND CLOSING FILE
	i = 0;
	while (i < canvas_height)
	{
		free (canvas[i]);
		canvas[i] = NULL;
		i++;
	}
	free (canvas);
	canvas = NULL;
	fclose(fd);
	return (0);
}
