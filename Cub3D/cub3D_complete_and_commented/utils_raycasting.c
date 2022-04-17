#include "cub3d.h"

int		wall_check(t_all *a, float x, float y)
{
	int		map_x;
	int		map_y;

	if (x < 0 || x > a->mlx.win_width || y < 0 || y > a->mlx.win_height)
		return (FALSE);
	if ((map_x = floor(x / a->map.tile)) >= a->map.max_width)
		map_x = a->map.max_width - 1;
	if ((map_y = floor(y / a->map.tile)) >= a->map.n_lines)
		map_y = a->map.n_lines - 1;
	if (a->map.matrix[map_y][map_x] == '1')
		return (1);
	else
		return (0);
}

int		spr_check(t_all *a, float x, float y)
{
	int		map_x;
	int		map_y;

	if (x < 0 || x > a->mlx.win_width || y < 0 || y > a->mlx.win_height)
		return (FALSE);
	map_x = floor(x / a->map.tile);
	map_y = floor(y / a->map.tile);
	if (a->map.matrix[map_y][map_x] == '2')
		return (TRUE);
	else
		return (FALSE);
}

void	ray_facing(t_all *a, int id)
{
	a->ray[id].is_ray_facing_d = a->ray[id].ray_angle
		> 0 && a->ray[id].ray_angle < PI;
	a->ray[id].is_ray_facing_u = a->ray[id].ray_angle
		> PI && a->ray[id].ray_angle < TWO_PI;
	a->ray[id].is_ray_facing_r = a->ray[id].ray_angle
		< 0.5 * PI || a->ray[id].ray_angle > 1.5 * PI;
	a->ray[id].is_ray_facing_l = a->ray[id].ray_angle
		> 0.5 * PI && a->ray[id].ray_angle < 1.5 * PI;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
