#include "cub3d.h"

void	get_parameters_from_file(t_all *a, char *map_file)
{
	a->aux.fd = open(map_file, O_RDONLY);
	while ((get_next_line(&a->aux.line, a->aux.fd)) > 0)		// Read the map for the firs time
	{
		a->aux.i = 0;
		while (a->aux.line[a->aux.i] == ' ' || a->aux.line[a->aux.i] == '\t')	// Jump over spces and tabs
			a->aux.i++;
		if (a->aux.line[a->aux.i] == '\0')
			ft_free(a->aux.line);
		if (ft_isdigit(a->aux.line[a->aux.i]) != 1)					// If line doesn't start with number...
			check_identifier(a);								// call the apropiate function based on the identifier
		else
		{
			if (!a->mlx.win_width || !a->mlx.win_height || !a->param.c_color ||
				!a->param.f_color || !a->param.text_no || !a->param.text_so
				|| !a->param.text_we ||!a->param.text_ea
				|| !a->param.text_spr)
				error_out(a, 16);
			a->map.n_lines++;									// If line start with number we've reached the map...
			a->aux.j = ft_strlen(a->aux.line);							// and we should check each line lenght and keep...
			if (a->aux.j > a->map.max_width)							// the value of the longest one to use it later
				a->map.max_width = a->aux.j;
			ft_free(a->aux.line);
		}
	}
	close(a->aux.fd);
}

void	check_identifier(t_all *a)								// Call the apropiate function based on identifier
{
	unsigned int i;

	i = 0;
	while (a->aux.line[i] == ' ' || a->aux.line[i] == '\t')
		i++;
	if (a->aux.line[i] == 'R' && a->aux.line[i + 1] == ' ')
		get_resolution(a);
	if (a->aux.line[i] == 'F' && a->aux.line[i + 1] == ' ')
		get_colors(a, 'f');
	if (a->aux.line[i] == 'C' && a->aux.line[i + 1] == ' ')
		get_colors(a, 'c');
	if (a->aux.line[i] == 'N' && a->aux.line[i + 1] == 'O'
		&& a->aux.line[i + 2] == ' ')
		get_texture(a, 'N');
	if (a->aux.line[i] == 'S' && a->aux.line[i + 1] == 'O'
		&& a->aux.line[i + 2] == ' ')
		get_texture(a, 'S');
	if (a->aux.line[i] == 'W' && a->aux.line[i + 1] == 'E'
		&& a->aux.line[i + 2] == ' ')
		get_texture(a, 'W');
	if (a->aux.line[i] == 'E' && a->aux.line[i + 1] == 'A'
		&& a->aux.line[i + 2] == ' ')
		get_texture(a, 'E');
	if (a->aux.line[i] == 'S' && a->aux.line[i + 1] == ' ')
		get_texture(a, 's');
}

void	get_resolution(t_all *a)
{
	int i;

	i = 0;
	while (!ft_isdigit(a->aux.line[i]))											// Skip all non numeric characters
		i++;
	while (a->aux.line[i] >= '0' && a->aux.line[i] <= '9')						// Convert each adjacent numeric character into a int variable...
		a->mlx.win_width = a->mlx.win_width * 10 + (a->aux.line[i++] - 48);		// ...to get the horizontal resolution
	while (!ft_isdigit(a->aux.line[i]))											// Skip all non numeric characters
		i++;
	while (a->aux.line[i] >= '0' && a->aux.line[i] <= '9')						// Convert each adjacent numeric character into a int variable...
		a->mlx.win_height = a->mlx.win_height * 10 + (a->aux.line[i++] - 48);	// ...to get the vertical resolution
	ft_free(a->aux.line);
}

void	get_colors(t_all *a, int c)
{
	unsigned int rgb;

	a->aux.i = 0;
	while (!ft_isdigit(a->aux.line[a->aux.i]))									// Skip all non numeric characters
		a->aux.i++;
	while (a->aux.line[a->aux.i] >= '0' && a->aux.line[a->aux.i] <= '9')		// Convert each adjacent numeric character into a int variable...
		a->aux.r = a->aux.r * 10 + (a->aux.line[a->aux.i++] - 48);
	a->aux.i++;
	while (!ft_isdigit(a->aux.line[a->aux.i]))									// Skip all non numeric characters
		a->aux.i++;
	while (a->aux.line[a->aux.i] >= '0' && a->aux.line[a->aux.i] <= '9')		// Convert each adjacent numeric character into a int variable...
		a->aux.g = a->aux.g * 10 + (a->aux.line[a->aux.i++] - 48);
	a->aux.i++;
	while (!ft_isdigit(a->aux.line[a->aux.i]))									// Skip all non numeric characters
		a->aux.i++;
	while (a->aux.line[a->aux.i] >= '0' && a->aux.line[a->aux.i] <= '9')		// Convert each adjacent numeric character into a int variable...
		a->aux.b = a->aux.b * 10 + (a->aux.line[a->aux.i++] - 48);
	check_color_values(a, a->aux.r, a->aux.g, a->aux.b);						// Check if values are between 0 and 256
	rgb = 65536 * a->aux.r + 256 * a->aux.g + a->aux.b;							// Convert three individual values into a just one
	reset_r_g_b(a);																// Reset color variables to be re-used
	if (c == 'c')
		a->param.c_color = rgb;													// Asign color to floor or ceiling
	else if (c == 'f')
		a->param.f_color = rgb;
	ft_free(a->aux.line);
}

void	get_texture(t_all *a, int c)
{
	unsigned int i;

	i = 0;
	while (a->aux.line[i] == ' ' || a->aux.line[i] == '\t')						// Skip spaces and tabulators
		i++;
	while (a->aux.line[i] >= 'A' && a->aux.line[i] <= 'Z')						// Skip identifier
		i++;
	while (a->aux.line[i] == ' ' || a->aux.line[i] == '\t')						// Skip spaces and tabulators
		i++;
	if (a->aux.line[i] == '\0')													// If there is no texture path send error message
		error_out(a, 8);
	else
	{
		if (c == 'N')															// Asign path to each texture variable
			a->param.text_no = ft_strdup(a->aux.line + i);
		if (c == 'S')
			a->param.text_so = ft_strdup(a->aux.line + i);
		if (c == 'W')
			a->param.text_we = ft_strdup(a->aux.line + i);
		if (c == 'E')
			a->param.text_ea = ft_strdup(a->aux.line + i);
		if (c == 's')
			a->param.text_spr = ft_strdup(a->aux.line + i);
	}
	ft_free(a->aux.line);
}
