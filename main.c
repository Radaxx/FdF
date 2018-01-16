/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:23:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/16 15:12:00 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_error("Usage: ./fdf <map>", EXIT_FAILURE);
	get_map(&env, av[1]);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 500, 500, "FdF");
	mlx_key_hook(env.win, ft_key, 0);
	mlx_loop(env.mlx);
}
