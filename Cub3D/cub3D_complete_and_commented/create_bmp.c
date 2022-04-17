#include "cub3d.h"

void	create_bmp(t_all *a)
{
	int		fd;
	int		file_size;
	int		first_pix;
	char	*name;

	name = "first_image.bmp";
	fd = open(name, O_CREAT | O_RDWR, 00600);
	file_size = 14 + 40 + 4 + (a->mlx.win_width * a->mlx.win_height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(a, fd);
	mir_verti(a);
	data_to_bitmap(a, fd);
	close(fd);
	exit_game(a);
}

void	bitmap_info_header(t_all *a, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &a->mlx.win_width, 4);
	write(fd, &a->mlx.win_height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &a->img.bits_per_pixel, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
}

void	mir_verti(t_all *a)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while ((unsigned int)line_cnt < a->mlx.win_height)
	{
		e = 0;
		f = a->img.line_length;
		while (e < f && e != f)
		{
			mir_verti_pixel(a, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
}

void	mir_verti_pixel(t_all *a, int line_cnt, int *e, int f)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = a->img.addr[*e + (line_cnt * a->img.line_length)];
		a->img.addr[*e + (line_cnt * a->img.line_length)] =
			a->img.addr[f - k + (line_cnt * a->img.line_length - 1)];
		a->img.addr[f - k + (line_cnt * a->img.line_length - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

void	data_to_bitmap(t_all *a, int fd)
{
	int i;

	i = a->mlx.win_width * a->mlx.win_height - 1;
	while (i >= 0)
	{
		write(fd, &a->img.addr[i * a->img.bits_per_pixel / 8], 4);
		i--;
	}
}
