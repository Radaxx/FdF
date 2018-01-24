/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:23:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/24 15:56:18 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_hook(int keycode, t_env *env)
{
	key_move(keycode, env);
	reload_win(env);
	return (0);
}

static void		init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("Error: MLX_INIT failed.\n", EXIT_FAILURE);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fil de Fer")))
		ft_error("Error: MLX_NEW_WINDOW failed.\n", EXIT_FAILURE);
}

static void		var_set(t_env *env)
{
	env->color_1 = WHITE;
	env->color_2 = BLUE;
	env->zoom = 15;
	env->x_move = 1000;
	env->y_move = 600;
	env->depth = -2;
	env->dec_width = 1;
	env->dec_height = 2;
	env->width = 0;
	env->height = 0;
	env->x_rot = 0;
}

int		expose_func(t_env *env)
{
	draw(env);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac != 2)
		ft_error("Usage: ./fdf <map>\n", EXIT_FAILURE);
	init_mlx(&env);
	var_set(&env);
	get_map(&env, av[1]);
	env.dot = set_matrice(&env);
	set_var(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_func, &env);
	mlx_loop(env.mlx);
	return (0);
}
