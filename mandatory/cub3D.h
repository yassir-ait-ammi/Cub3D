/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:47:49 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/28 10:51:50 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libhb/libhb.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define EXIT 65307
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define W 119
# define S 115
# define MINI 150
# define COLLISION_RADIUS 5.0
# define EPSILON 0.0001
# define VIEW_RANGE 5
# define MINI_TILE 10

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		txtr_w;
	int		txtr_h;
	char	*path;
}			t_img;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;

}			t_dda;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		x;
	int		y;
	int		e2;
	int		i;
	int		j;
	int		r;
	int		color;
}			t_line;

typedef struct s_render
{
	double	camera_x;
	double	ray_angle;
	double	distance;
	double	originangle;
	int		wall_height;
	int		draw_start;
	int		draw_end;
	int		x;
}			t_render;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*weast;
	char	*east;
	char	*sky;
	char	*ground;
	char	*map;
	int		orgx;
	int		orgy;
	size_t	xmax;
	size_t	ymax;
}			t_data;

typedef struct s_por
{
	int		screen_x;
	int		screen_y;
	int		tex_x;
	int		tex_y;
	ssize_t	color;
	float	scale_x;
	float	scale_y;
}				t_por;

typedef struct s_cub3d
{
	int		floor;
	void	*mlx;
	void	*win;
	double	player_x;
	double	player_y;
	double	player_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	int		*hitside;
	t_img	no_texture;
	t_img	so_texture;
	t_img	we_tex;
	t_img	ea_texture;
	t_img	dor_tex;
	t_img	*por_tex;
	t_img	img;
	char	**map;
	int		sky;
	t_data	*data;
	double	wall;
	char	direction;
	double	x_wind;
	double	y_wind;
	int		tile;
	int		hitype;
	int		color_cub;
	int		teleporting;
	int		anim_current_frame;
	int		anim_max_frames;
	int		anim_frame_delay;
	int		anim_delay_counter;
	int		anim_active;
}			t_cub3d;

int			is_valide(char c);
void		ft_exit(int e);
void		put_pixel(t_cub3d *data, int x, int y, unsigned int color);
int			parsing(char *filename);
int			is_required(char c);
int			check_valid_map(char *filename, t_data **data);
int			validate_map(char *input);
int			is_space(char c);
void		store_the_appropriate(char *str, t_data **data);
t_cub3d		*init_data_for_simulation(t_data *data);
double		dda(t_cub3d *data);
void		render(t_cub3d *data);
int			key_press(int keycode, t_cub3d *data);
int			is_player_char(char c);
void		texturi_lwall(t_cub3d *data, t_render *r);
void		draw_mini_map(t_cub3d *all);
int			clean_exit(t_cub3d *all);
int			mouse_move(int x, int y, t_cub3d *data);
void		initialize(t_data *data);
void		init_all(t_cub3d *all);
void		textures(t_cub3d *all);
void		init_tex(t_cub3d *all);
void		init_angle(t_cub3d *all);
void		find_position(t_cub3d *all);
size_t		get_maxwidth(char **map);
void		open_door(t_cub3d *data);
void		move_player(t_cub3d *data, double newx, double newy);
int			dirs(int i, int j);
void		put_pixel_for_mini(t_img *img, int x, int y, int color);
void		draw_square(t_cub3d *all, int x, int y, int size);
void		ternaries(int a, int b, int *x);
int			is_invalid_border(char **map, int x, int y, int rows);
double		normalize_angle(double angle);
ssize_t		get_texture_pixel(t_img *texture, int x, int y);
int			tp(t_cub3d *data);
void		rotation_rows(t_cub3d *data, int keycode);

#endif
