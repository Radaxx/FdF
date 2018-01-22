/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:23:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/22 17:06:26 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static void		init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("Error: MLX_INIT failed.\n", EXIT_FAILURE);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fil de Fer")))
		ft_error("Error: MLX_NEW_WINDOW failed.\n", EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_error("Usage: ./fdf <map>\n", EXIT_FAILURE);
	init_mlx(&env);
	get_map(&env, av[1]);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
