/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/29 13:10:17 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

# define WHITE 0xFFFFFF
# define BLUE 0x0000FF

# define ESCAPE 53
# define LOW_ROT 43
# define HIGH_ROT 47
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 125
# define DOWN_ARROW 126
# define ZOOM_PLUS 69
# define ZOOM_MOINS 78
# define DEPTH_PLUS 121
# define DEPTH_MOINS 116

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_var
{
	char			*line;
	int				fd;
	int				i;
	int				j;
}					t_var;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				i;
	int				f;
	int				inc_1;
	int				inc_2;
	int				inc_x;
	int				inc_y;
	int				x;
	int				y;
}					t_line;

typedef struct		s_dot
{
	double			x;
	double			x_min;
	double			x_max;
	double			y;
	double			y_min;
	double			y_max;
	double			z;
	double			z_max;
	double			color;
}					t_dot;

typedef struct		s_mat
{
	int				x;
	int				y;
	int				i;
}					t_mat;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			**u_map;
	int				**map;
	int				width;
	int				height;
	int				depth;
	int				zoom;
	int				x_move;
	int				y_move;
	int				color_1;
	int				color_2;
	double			x_rot;
	double			dec_width;
	double			dec_height;
	t_dot			**dot;
}					t_env;

int					expose_func(t_env *env);
void				var_set(t_env *env);
void				reload_win(t_env *env);
void				key_move(int keycode, t_env *env);
void				get_map(t_env *env, char *av);
void				set_var(t_env *env);
void				draw(t_env *env);
t_dot				**set_matrice(t_env *env);

#endif
