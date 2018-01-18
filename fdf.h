/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/18 10:58:27 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>

typedef struct		s_dot
{
	double		x;
	double		y;
	double		z;
}					t_dot;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		**map;
}					t_env;

void	get_map(t_env *env, char *av, int fd);
int		ft_key(int keycode, void *param);

#endif
