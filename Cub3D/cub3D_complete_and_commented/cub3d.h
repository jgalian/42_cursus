#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	unsigned int	win_width;
	unsigned int	win_height;
}					t_mlx;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef	struct		s_aux
{
	char			*line;
	char			*line2;
	int				fd;
	char			*map_file;
	int				r;
	int				g;
	int				b;
	int				i;
	int				j;
	int				x;
	int				y;
	int				pos_x;
	int				pos_y;
	int				pos_sx;
	int				pos_sy;
	char			*err_message[20];
	int				num_rays;
	int				first_time;
	float			step;
	float			pos_x_text;
	float			pos_y_text;
}					t_aux;

typedef struct		s_param
{
	char			*text_no;
	char			*text_so;
	char			*text_ea;
	char			*text_we;
	char			*text_spr;
	char			*text_f;
	char			*text_c;
	unsigned int	f_color;
	unsigned int	c_color;
}					t_param;

typedef struct		s_map
{
	char			**matrix;
	int				n_lines;
	int				max_width;
	int				zero;
	int				player_initial_position_exist;
	float			player_initial_position_x;
	float			player_initial_position_y;
	char			player_start_angle;
	int				tile;
	int				spr_count;
}					t_map;

typedef struct		s_play {
	float			x;
	float			y;
	int				size;
	int				turn_dir;
	int				walk_dir;
	float			lateral_mov;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;
	float			dist_proyection_plane;
}					t_play;

typedef struct		s_text
{
	void			*img;
	char			*addr;
	int				height;
	int				width;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_text;

typedef struct		s_bmp
{
	void			*img;
	char			*addr;
	int				height;
	int				width;
	int				bits_per_pixel;
}					t_bmp;

typedef struct		s_spr_text
{
	void			*img;
	char			*addr;
	int				height;
	int				width;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_spr_text;

typedef struct		s_spr
{
	float			spr_x;
	float			spr_y;
	float			spr_play_angle;
	float			spr_play_angle_abs;
	float			vector_x;
	float			vector_y;
	int				spr_map_x;
	int				spr_map_y;
	int				visible;
	float			spr_play_distance;
	int				start_render_x;
	int				end_render_x;
	int				start_render_y;
	int				end_render_y;
	int				height;
}					t_spr;

typedef struct		s_ray_aux
{
	float			horz_hit_dist;
	float			horz_wall_hit_x;
	float			horz_wall_hit_y;
	int				horz_wall_content;
	float			horz_xstep;
	float			horz_ystep;
	float			vert_hit_dist;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	int				vert_wall_content;
	float			vert_xstep;
	float			vert_ystep;
	int				found_horz_wall_hit;
	int				found_vert_wall_hit;
	float			x_to_check;
	float			y_to_check;
	int				w_strip_height;
}					t_ray_aux;

typedef struct		s_ray
{
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				was_hit_vertical;
	int				is_ray_facing_u;
	int				is_ray_facing_d;
	int				is_ray_facing_l;
	int				is_ray_facing_r;
	int				wall_hit_content;
}					t_ray;

typedef struct		s_all
{
	t_img			img;
	t_bmp			bmp;
	t_mlx			mlx;
	t_aux			aux;
	t_map			map;
	t_param			param;
	t_play			play;
	t_text			text[4];
	t_spr_text		spr_text[1];
	t_spr			*spr;
	t_ray			*ray;
	t_ray_aux		ray_aux;
}					t_all;

void				get_parameters_from_file(t_all *a, char *map_file);
void				get_map_matrix(t_all *a, char *argv);
void				validate_map_info(t_all *a);
int					error_out(t_all *a, int err_num);
int					get_next_line(char **line, int fd);
int					ft_isdigit(int c);
void				ft_free(char *s);
size_t				ft_strlen(char *s);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s, char *p);
char				*ft_strdup(char *s);
void				skip_spaces(char *s);
int					ft_get_output(char **line, int bt, char **gnl);
void				init_variables(t_all *a);
void				reset_r_g_b(t_all *a);
void				other_map_validations(t_all *a);
void				set_error_messages(t_all *a);
void				game_setup(t_all *a);
int					key_press(int keycode, t_all *a);
int					key_release(int keycode, t_all *a);
int					exit_game(t_all *a);
void				update(t_all *a);
int					wall_check(t_all *a, float x, float y);
float				distance_between_points(float x1, float y1, float x2, float y2);
float				normalize_angle(float angle);
void				ray_facing(t_all *a, int id);
void				assign_pixel(t_all *a);
//void				draw_map(t_all *a);
void				horizontal_intersection(t_all *a, int strip_id);
void				vertical_intersection(t_all *a, int strip_id);
void				my_mlx_pixel_put(t_all *a, int x, int y, int color);
//void				draw_player(t_all *a);
void				draw_point(t_all *a);
void				render(t_all *a);
void				raycast(t_all *a);
void				draw_columns(t_all *a);
int					mouse_click(int click_code, t_all *a);
int					spr_check(t_all *a, float x, float y);
void				clean_spr_variables(t_all *a);
int					check_spr_id(t_all *a, float x, float y);
void				draw_sprites(t_all *a);
void				get_wall_textures(t_all *a);
void				get_sprites_textures(t_all *a);
void				count_sprites(t_all *a);
void				get_sprite_data(t_all *a);
void				check_color_values(t_all *a, int r, int g, int b);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				create_bmp(t_all *a);
void				update_sprites(t_all *a);
void				get_spr_render_start_point(t_all *a, int id);
void				sort_sprites(t_all *a);
void				ft_swap(t_spr *spr1, t_spr *spr2);
int 				main_loop(t_all *a);
int					one_time_main_loop(t_all *a, int argc);
void				bitmap_info_header(t_all *a, int fd);
void				mir_verti(t_all *a);
void				mir_verti_pixel(t_all *a, int line_cnt, int *e, int f);
void				data_to_bitmap(t_all *a, int fd);
void				resolution_and_tile_size(t_all *a);
void				player_initial_position(t_all *a);
void				set_player_speed(t_all *a);
void				get_wall_textures(t_all *a);
void				get_sprites_textures(t_all *a);
void				count_sprites(t_all *a);
void				get_sprite_data(t_all *a);
void				map_to_matrix(t_all *a);
void				check_identifier(t_all *a);
void				get_resolution(t_all *a);
void				get_colors(t_all *a, int c);
void				get_texture(t_all *a, int c);
void				validate_parameters(t_all *a);
void				validate_textures(t_all *a);
void				validate_map_horizontal_limits(t_all *a);
void				validate_map_vertical_limits(t_all *a);
void				draw_map(t_all *a);
void				draw_rays(t_all *a);
void				draw_player(t_all *a);
//void				draw_line(t_all *a);
void				check_horizontal_collision(t_all *a, float xintercept,
					float yintercept, int id);
void				check_vertical_collision(t_all *a, float xintercept,
					float yintercept, int id);
void				cast_individual_ray(t_all *a, int id);
void				check_shortest_hit_distance(t_all *a, int id);
void				draw_walls(t_all *a, int i, float w_top_pix, float w_bot_pix);
void				draw_ceiling_and_floor(t_all *a, int i, float w_top_pix,
					float w_bot_pix);
unsigned int		get_color_from_texture(t_all *a, int i, int texture_offset_x,
					int texture_offset_y);
void				draw_sprite(t_all *a, int id);
void				get_sprite_color_from_texture(t_all *a, int x, int y);
int					get_map_position(t_all *a, float f);
int					is_new_position_ok(t_all *a, float new_map_x, float new_map_y,
					int map[]);
void				check_new_position(t_all *a, float new_x, float new_y);

# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define FALSE					0
# define TRUE					1

# define PI						3.14159265
# define TWO_PI					6.28318530

# define MINIMAP_SCALE_FACTOR	0.2

# define FOV_ANGLE				1.0471975512

# define ROJO					16711680
 # define VERDE					65280
// # define AZUL					255
 # define NEGRO					0x00000000
 # define BLANCO					0x00FFFFFF
// # define BLANCO_SUCIO			0x00CCCCCC
 # define GRIS_CLARO				0x00777777
// # define GRIS_OSCURO			0x00333333

# define INT_MAX				2147483647

#endif
