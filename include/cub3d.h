/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:13 by akoutsou          #+#    #+#             */
/*   Updated: 2023/09/07 13:38:11 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define PI 3.141592653589793
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_R 114
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_render
{
	int			start;
	int			end;
	int			color;
}				t_render;

typedef struct s_ray
{
	double		ray_angle;
	double		currentx;
	double		currenty;
	double		raycos;
	double		raysin;
	double		dist;
	double		wallheight;
	int			direction;
}				t_ray;

typedef struct s_column
{
	int			sky_start;
	int			sky_end;
	int			sky_color;
	int			wall_start;
	int			wall_end;
	int			wall_color;
	int			floor_start;
	int			floor_end;
	int			floor_color;
	int			colnbr;
	int			direction;
	double		currenty;
	double		currentx;
}				t_column;

typedef struct s_vectors
{
	double		x;
	double		y;
}				t_vectors;

typedef struct s_colors
{
	int			r;
	int			g;
	int			b;
}				t_colors;

typedef struct s_tex
{
	char		*path;
	char		*data;
	void		*ptr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			currenty;
}				t_tex;

typedef struct s_camera
{
	t_vectors	pos;
	t_vectors	dir;
	t_vectors	x_dir;
	t_vectors	plane;
}				t_camera;

typedef struct s_program
{
	t_camera	camera;
	t_colors	color[2];
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		img;
	t_vectors	size;
	void		*mlx;
	char		**map;
	int			error;
	double		spawn_x;
	double		spawn_y;
	double		angle;
	void		*win_ptr;
	double		half_h;
	double		half_w;
	double		fov;
	double		half_fov;
	double		rc_incrementing;
	int			rdelay;
	int			rc_precision;
	int			i;
	int			j;
	int			number_of_rows;
	int			flag;
}				t_program;

void			ft_create_window(t_program *prg);
void			ft_push_tex(t_program *prg);
void			ft_spawn(t_program *prg);
unsigned int	ft_color_converter(int r, int g, int b);
double			ft_degrees_to_radiants(double degrees);
unsigned int	ft_mlx_pixel_get(t_tex *data, int x, int y);
void			ft_render_pixel(t_tex img, int x, int y, int color);
void			ft_render_full_column(t_program *prg, t_tex img,
					t_column column);
int				ft_is_direction(char c);
void			ft_raycasting(t_program *prg);
int				ft_handlekeys(int ks, t_program *prg);
int				ft_close(t_program *program);
void			ft_take_file_and_check(char **argv, t_program *program);
int				ft_handlekeys(int ks, t_program *prg);
int				ft_check_map_line_charset(char *line);
int				ft_check_vert_zero(char **map, int i, int j);
int				ft_check_horiz_zero(char **map, int i, int j);
int				ft_check_map(char **map);
void			ft_take_map(t_program *program, char **file);
int				ft_maplen(char **file);
int				ft_map_start(char **file);
int				ft_otherline_after(char **file, int i);
char			*ft_strdup_map(char *str);
int				ft_check_tex_and_color(t_program *program);
int				ft_check_param_num(char **file);
void			ft_take_tex_and_color(t_program *program, char **file, int i);
void			ft_color_err(t_colors *color);
int				ft_atoi_special(char *str);
int				ft_isspace(char c);
int				ft_strlen_special(char *str);
char			*ft_strdup_special(char *str);
void			ft_move_down(t_program *prg, double playercos,
					double playersin);
void			ft_move_up(t_program *prg, double playercos, double playersin);
void			ft_move_right(t_program *prg, double playercos,
					double playersin);
void			ft_move_left(t_program *prg, double playercos,
					double playersin);

#endif
