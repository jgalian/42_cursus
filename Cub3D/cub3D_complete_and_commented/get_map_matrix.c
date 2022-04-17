#include "cub3d.h"

void	get_map_matrix(t_all *a, char *argv)
{
	int i;
	int j;

	a->aux.fd = open(argv, O_RDONLY);										// Open the file send as argument
	if (!(a->map.matrix = (char**)malloc(sizeof(char*) * a->map.n_lines)))	// Allocate memory for each line in the map
		error_out(a, 1);
	i = 0;
	while (i < a->map.n_lines)
	{
		if (!(a->map.matrix[i] = (char *)malloc(a->map.max_width + 1)))		// Allocate memory for each line...
			error_out(a, 1);												// ...based on the line with more characters on it
		j = 0;
		while (j < a->map.max_width)
		{
			a->map.matrix[i][j] = ' ';										// Fill each memory place in the matrix with ' '
			j++;
		}
		a->map.matrix[i][j] = '\0';											// End each file with '\0' terminator
		i++;
	}
	map_to_matrix(a);														// Call function to get the values for the matrix
	close(a->aux.fd);														// Close the file send as argument
}

void	map_to_matrix(t_all *a)
{
	int i;
	int j;

	i = 0;
	while ((get_next_line(&a->aux.line2, a->aux.fd)) > 0)					// Read each line
	{
		j = 0;
		while (a->aux.line2[j] == ' ' || a->aux.line2[j] == '\t')			// Skip spaces and tabulators
			j++;
		if (ft_isdigit(a->aux.line2[j]) == TRUE)							// When located the first line starting with a number...
		{																	// ...is where map starts
			j = 0;
			while (a->aux.line2[j])											// While a position in line would have content...
			{																// ...copy the value to the matrix
				a->map.matrix[i][j] = a->aux.line2[j];
				j++;
			}
			i++;
		}
		ft_free(a->aux.line2);
	}
}
