/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:23:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/17 17:55:07 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *win, int (*funct_ptr)(), void *param)
{

	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;
	t_map	map;
	int		fd;

	if (ac != 2)
		ft_error("Usage: ./fdf <map>", EXIT_FAILURE);
	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	if (!(env.mlx = mlx_init()))
		ft_error("Error: MLX_INIT failed.\n", EXIT_FAILURE);
	get_map(&env, &map, av[1], fd);
	env.win = mlx_new_window(env.mlx, 500, 500, "FdF");
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, ft_key, 0);
	mlx_loop(env.mlx);
	return (0);
}
