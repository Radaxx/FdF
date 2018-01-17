/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/17 15:45:44 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>

typedef struct		s_dot
{
	int		x;
	int		y;
	int		z;
}					t_dot;

typedef struct		s_map
{
	int		xmax;
	int		ymax;
	int		**map;
}					t_map;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	t_map	*map;
}					t_env;

void	get_map(t_env *env, t_map *mp, char *av, int fd);
int		ft_key(int keycode, void *param);

#endif
