/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 19:16:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/02 23:57:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65451)
	{
		ft_putstr("Zoom ++\n");
		env->zoom += 100;
		env->origin_img->x -= 50;
		env->origin_img->y -= 25;
	}
	if (keycode == 65453)
	{
		ft_putstr("Zoom --\n");
		env->zoom -= 100;
		if (env->zoom <= 10)
		{
			env->zoom = 10;
		}
		else
		{
			env->origin_img->x += 50;
			env->origin_img->y += 25;
		}

	}
	if (keycode == 65362)
		env->origin_img->y -= 10;
	if (keycode == 65364)
		env->origin_img->y += 10;
	if (keycode == 65361)
		env->origin_img->x -= 10;
	if (keycode == 65363)
		env->origin_img->x += 10;
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->width_img, env->height);
	ft_zoom_tab(env, env->memo);
	ft_make_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (keycode == 65307)
		exit(0);
	return (0);
}
