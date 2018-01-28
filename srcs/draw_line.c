/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:13:29 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/28 16:17:28 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_env *env, t_line *line, int color)
{
	mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
	line->f = 2 * line->dx - line->dy;
	line->inc_1 = 2 * (line->dx - line->dy);
	line->inc_2 = 2 * line->dx;
	line->i = 0;
	while (line->i < line->dy)
	{
		if (line->f >= 0)
		{
			line->x += line->inc_x;
			line->f += line->inc_1;
		}
		else
			line->f += line->inc_2;
		line->y += line->inc_y;
		mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
		line->i++;
	}
}

static void		draw_horizontal(t_env *env, t_line *line, int color)
{
	mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
	line->f = 2 * line->dy - line->dx;
	line->inc_1 = 2 * (line->dy - line->dx);
	line->inc_2 = 2 * line->dy;
	line->i = 0;
	while (line->i < line->dx)
	{
		if (line->f >= 0)
		{
			line->y += line->inc_y;
			line->f += line->inc_1;
		}
		else
			line->f += line->inc_2;
		line->x += line->inc_x;
		mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
		line->i++;
	}
}

static void		draw_line(t_dot *m1, t_dot *m2, t_env *env)
{
	t_line		*line;

	line = (t_line *)ft_xmalloc(sizeof(t_line));
	line->dx = m2->x_min - m1->x_min;
	line->dy = m2->y_min - m1->y_min;
	line->dx = ft_isabs(line->dx);
	line->dy = ft_isabs(line->dy);
	line->inc_x = (m2->x_min < m1->x_min) ? -1 : 1;
	line->inc_y = (m2->y_min < m1->y_min) ? -1 : 1;
	line->x = m1->x_min;
	line->y = m1->y_min;
	(line->dx > line->dy) ? draw_horizontal(env, line, m1->color) :
		draw_vertical(env, line, m1->color);
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void			draw(t_env *env)
{
	int			i;

	i = 0;
	while (env->dot[i])
	{
		if (env->dot[i]->z_max > 3 || env->dot[i]->z_max < (-3))
			env->dot[i]->color = env->color_2;
		else
			env->dot[i]->color = env->color_1;
		if ((i + 1) % env->width != 0)
			draw_line(env->dot[i], env->dot[i + 1], env);
		if (i < ((env->width * env->height) - env->width))
			draw_line(env->dot[i], env->dot[i + env->width], env);
		i++;
	}
}
