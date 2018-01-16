/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/16 13:34:32 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		**map;
	int		xmax;
	int		ymax;
}					t_env;

t_env	*get_map(t_env *env, char *av);
void	check_size(t_env *env, char **map);
void	check_height(t_env *env, char *str);
int		ft_key(int keycode, void *param);


#endif
