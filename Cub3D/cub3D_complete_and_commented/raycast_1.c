#include "cub3d.h"

void		raycast(t_all *a)
{
	int		id;

	id = 0;
	a->ray[id].ray_angle = a->play.rotation_angle - (FOV_ANGLE / 2);	// Find the first ray starting to the left
	while (id < a->aux.num_rays)										// Loop to cast each individual ray
	{
		cast_individual_ray(a, id);
		if (id + 1 < a->aux.num_rays)
			a->ray[id + 1].ray_angle = a->ray[id].ray_angle +
				(FOV_ANGLE / (float)a->mlx.win_width);
		id++;
	}
}

void		cast_individual_ray(t_all *a, int id)
{
	a->ray[id].ray_angle = normalize_angle(a->ray[id].ray_angle);		// Avoid the angle be < 0º or > que 360º
	ray_facing(a, id);													// Save where the ray is pointing
	horizontal_intersection(a, id);										// Check the horizontal intersections until a wall is hit
	vertical_intersection(a, id);										// Check the verticcal intersections until a wall is hit
	if (a->ray_aux.found_horz_wall_hit == TRUE &&
		a->ray_aux.found_vert_wall_hit == FALSE)						// If only horizontal intersections found a wall hit...
	{																	// ... set flags and use that distance
		a->ray[id].distance = a->ray_aux.horz_hit_dist;
		a->ray[id].was_hit_vertical = FALSE;
		a->ray[id].wall_hit_x = a->ray_aux.horz_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.horz_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.horz_wall_content;
	}
	else if (a->ray_aux.found_horz_wall_hit == FALSE &&					// If only vertical intersections found a wall hit...
		a->ray_aux.found_vert_wall_hit == TRUE)							// ... set flags and use that distance
	{
		a->ray[id].distance = a->ray_aux.vert_hit_dist;
		a->ray[id].was_hit_vertical = TRUE;
		a->ray[id].wall_hit_x = a->ray_aux.vert_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.vert_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.vert_wall_content;
	}
	else
		check_shortest_hit_distance(a, id);								// If both get a hit compare distance and use only the shortest one
}

void		check_shortest_hit_distance(t_all *a, int id)
{
	if (a->ray_aux.horz_hit_dist < a->ray_aux.vert_hit_dist)
	{
		a->ray[id].was_hit_vertical = FALSE;
		a->ray[id].distance = a->ray_aux.horz_hit_dist;
		a->ray[id].wall_hit_x = a->ray_aux.horz_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.horz_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.horz_wall_content;
	}
	else
	{
		a->ray[id].distance = a->ray_aux.vert_hit_dist;
		a->ray[id].was_hit_vertical = TRUE;
		a->ray[id].wall_hit_x = a->ray_aux.vert_wall_hit_x;
		a->ray[id].wall_hit_y = a->ray_aux.vert_wall_hit_y;
		a->ray[id].wall_hit_content = a->ray_aux.vert_wall_content;
	}
}
