/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/23 15:17:14 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1024
# define HEIGHT 768

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

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
}					t_dot;

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
	double			x_rot;
	double			dec_width;
	double			dec_height;
	t_dot			**dot;
}					t_env;

void				get_map(t_env *env, char *av);
void				set_var(t_env *env);
void				draw(t_env *env);

#endif
