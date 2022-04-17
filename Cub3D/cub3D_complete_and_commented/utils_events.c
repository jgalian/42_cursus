#include "cub3d.h"

int		key_press(int keycode, t_all *a)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		a->play.walk_dir = +1;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		a->play.walk_dir = -1;
	if (keycode == KEY_A)
	{
		a->play.walk_dir = +1;
		a->play.lateral_mov = -0.5 * PI;
	}
	if (keycode == KEY_D)
	{
		a->play.walk_dir = +1;
		a->play.lateral_mov = 0.5 * PI;
	}
	if (keycode == KEY_LEFT)
		a->play.turn_dir = -1;
	if (keycode == KEY_RIGHT)
		a->play.turn_dir = +1;
	return (0);
}

int		key_release(int keycode, t_all *a)
{
	if (keycode == KEY_ESC)
		exit_game(a);
	if (keycode == KEY_UP)
		a->play.walk_dir = 0;
	if (keycode == KEY_DOWN)
		a->play.walk_dir = 0;
	if (keycode == KEY_W)
		a->play.walk_dir = 0;
	if (keycode == KEY_S)
		a->play.walk_dir = 0;
	if (keycode == KEY_A)
	{
		a->play.lateral_mov = 0;
		a->play.walk_dir = 0;
	}
	if (keycode == KEY_D)
	{
		a->play.lateral_mov = 0;
		a->play.walk_dir = 0;
	}
	if (keycode == KEY_LEFT)
		a->play.turn_dir = 0;
	if (keycode == KEY_RIGHT)
		a->play.turn_dir = 0;
	return (0);
}
