#include "cub3d.h"

void		draw_sprites(t_all *a)
{
	int		id;

	id = 0;
	while (id < a->map.spr_count)
	{
		if (a->spr[id].visible == TRUE)						// Draw only visible sprites
			draw_sprite(a, id);
		id++;
	}
}

void		draw_sprite(t_all *a, int id)
{
	int				x;
	int				y;

	a->aux.step = (float)a->spr_text[0].width / (float)a->spr[id].height;		// Compute the distance in the texture from pixel to pixel
	a->aux.pos_x_text = 0;														// Set start X coordinate in the texture array
	x = a->spr[id].start_render_x;												// X coordinate where start drawing on the image
	while (x < a->spr[id].end_render_x)											// Loop from start X coordinate to end X coordinate
	{
		if (x >= 0 && x < (int)a->mlx.win_width && a->spr[id].spr_play_distance
			< a->ray[x].distance)					// Protect having coordinates outside the map and drawing only if it is closer than a wall
		{
			a->aux.pos_y_text = 0;												// Set start Y coordinate in the texture array
			y = (int)a->spr[id].start_render_y;									// Y coordinate where start drawing on the image
			while (y < (int)a->spr[id].end_render_y)
			{
				if (y > 0 && y < (int)a->mlx.win_height)	// While inside the limits, draw texture vertical line of X coordinate
					get_sprite_color_from_texture(a, x, y);
				y++;
				a->aux.pos_y_text += a->aux.step;
			}
		}
		x++;
		a->aux.pos_x_text += a->aux.step;
	}
}

void	get_sprite_color_from_texture(t_all *a, int x, int y)
{
	char			*dst;
	unsigned int	texel_color;

	dst = a->spr_text[0].addr + ((int)a->aux.pos_y_text *
		a->spr_text[0].line_length + (int)a->aux.pos_x_text *
		(a->spr_text[0].bits_per_pixel / 8));
	texel_color = *(unsigned int*)dst;
	if (texel_color != NEGRO)													// Texture image is created over a black background...
		my_mlx_pixel_put(a, x, y, texel_color);									// ...to print only non black pixels
}
