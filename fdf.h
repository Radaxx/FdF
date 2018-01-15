/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:49:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/15 16:48:48 by aparabos         ###   ########.fr       */
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
}					t_env;

int		**get_map(char *av);
int		ft_key(int keycode, void *param);

#endif
