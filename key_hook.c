/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 19:16:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 21:47:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_rez(t_env *env)
{
	env->zoom = ft_max(env->height, env->width);
	env->origin_img->x = 0;
	env->origin_img->y = 0;
	env->angle[0] = 0;
	env->angle[1] = 0;
	env->angle[2] = 0;
	return (1);
}

static int	ft_zoom(int keycode, t_env *env)
{
	int		zoom_it;

	zoom_it = 0;
	if (keycode == 61)
	{
		env->zoom += 150;
		env->origin_img->x -= 50;
		env->origin_img->y -= 25;
		zoom_it = 1;
	}
	if (keycode == 45)
	{
		if (env->zoom - 150 > 10)
		{
			env->zoom -= 150;
			env->origin_img->x += 50;
			env->origin_img->y += 25;
		}
		zoom_it = 1;
	}
	if (keycode == 48)
		zoom_it = ft_rez(env);
	return (zoom_it);
}

static void	ft_rot(int keycode, t_env *env)
{
	if (keycode == 65362)
		env->origin_img->y -= 50;
	if (keycode == 65364)
		env->origin_img->y += 50;
	if (keycode == 65361)
		env->origin_img->x -= 50;
	if (keycode == 65363)
		env->origin_img->x += 50;
	if (keycode == 114)
		env->angle[0] -= 5;
	if (keycode == 116)
		env->angle[0] += 5;
	if (keycode == 102)
		env->angle[1] -= 5;
	if (keycode == 103)
		env->angle[1] += 5;
	if (keycode == 118)
		env->angle[2] -= 5;
	if (keycode == 98)
		env->angle[2] += 5;
}

int			key_hook(int keycode, t_env *env)
{
	int		zoom_it;

	zoom_it = 0;
	if (keycode == 65307)
		exit(0);
	else
	{
		zoom_it = ft_zoom(keycode, env);
		ft_rot(keycode, env);
	}
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->width_img, env->height);
	ft_proj_tab_iso(env);
	env->memo = ft_regu_tab(env);
	ft_zoom_tab(env, env->memo, zoom_it);
	ft_make_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
