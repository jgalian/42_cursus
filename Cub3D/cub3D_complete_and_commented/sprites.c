#include "cub3d.h"

void	update_sprites(t_all *a)
{
	int			id;
	float		vectors_angle;

	id = 0;
	while (id < a->map.spr_count)											// While there is a sprite
	{
		a->spr[id].vector_x = a->spr[id].spr_x - a->play.x;					// Calculate the diference between x and y coordinates...
		a->spr[id].vector_y = a->spr[id].spr_y - a->play.y;					// ... from player to the sprite, in order to use them to...
		vectors_angle = atan2(a->spr[id].vector_y, a->spr[id].vector_x);	// ... compute the angle between them
		a->spr[id].spr_play_angle = vectors_angle - a->play.rotation_angle;
		if (a->spr[id].spr_play_angle < (-1 * PI))							// Normalize angle
			a->spr[id].spr_play_angle += 2.0 * PI;
		if (a->spr[id].spr_play_angle > PI)
			a->spr[id].spr_play_angle -= 2.0 * PI;
		a->spr[id].spr_play_angle_abs = fabs(a->spr[id].spr_play_angle);	// Get absolute value for the angle in order to determine...
		if (a->spr[id].spr_play_angle >= -0.57735 && a->spr[id].			// ... if sprite is visible or not
			spr_play_angle<= 0.57735)
			a->spr[id].visible = TRUE;
		else
			a->spr[id].visible = FALSE;
		a->spr[id].spr_play_distance = distance_between_points(a->play.x,	// Get the distance between player and sprite
			a->play.y, a->spr[id].spr_x, a->spr[id].spr_y);
		get_spr_render_start_point(a, id);									// Call a function to get the coordinates where start drawing
		id++;
	}
}

void	get_spr_render_start_point(t_all *a, int id)
{
	float	aux_x;
	float	tangent;

	a->spr[id].height = (a->map.tile / a->spr[id].spr_play_distance)		// Get the sprite height based on the distance
		* a->play.dist_proyection_plane;									// Have in mind that sprite hight and width is the same
	a->spr[id].start_render_y = (a->mlx.win_height / 2) -					// Get y coordinate starting in the middle of the screen and...
		(a->spr[id].height / 2);											// ...substracting half ot the sprite height
	a->spr[id].end_render_y = a->spr[id].start_render_y + a->spr[id].height;// Adding sprite height to prior y value we get where to end drawing
	tangent = tan(a->spr[id].spr_play_angle);
	aux_x = tangent * a->play.dist_proyection_plane;						// Using the angle between player and sprite, and the distance to...
	a->spr[id].start_render_x = (a->mlx.win_width / 2 + aux_x) -			// ... the proyection plane x coordinate can be obtained
		(a->spr[id].height / 2);
	a->spr[id].end_render_x = a->spr[id].start_render_x + a->spr[id].height;// Get the xx coordinate where end drawing
}

void	sort_sprites(t_all *a)
{
	int		id;

	id = 0;
	while (id < a->map.spr_count - 1)										// Sort sprites based on distance to player
	{
		if (a->spr[id].spr_play_distance < a->spr[id + 1].spr_play_distance)
		{
			ft_swap(&a->spr[id], &a->spr[id + 1]);
			id = -1;
		}
		id++;
	}
}

void	ft_swap(t_spr *spr1, t_spr *spr2)
{
	t_spr	spr3;

	spr3 = *spr1;
	*spr1 = *spr2;
	*spr2 = spr3;
}
