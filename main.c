/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:57:20 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/02 23:54:53 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max(int n1, int n2)
{
	return ((n1 > n2) ? n1 : n2);
}

int		main(int ac, char **av)
{
	t_env	env;

	env.height = 800;
	env.width = 1500;
	env.height_img = env.height;
	env.width_img = env.width;
	env.zoom = ft_max(env.height, env.width);
	env.origin_img = (t_pt2d *)malloc(sizeof(t_pt2d));
	env.origin_img->x = 0;
	env.origin_img->y = 0;
	if (ac == 2)
	{
		ft_gettab(&env, av[1], &env.height_tab, &env.width_tab);
		ft_proj_tab_iso(&env);
		env.memo = ft_regu_tab(&env);
		ft_zoom_tab(&env, env.memo);

		if(!(env.mlx = mlx_init()))
		{
			ft_putendl("Probleme d'env");
			exit (1);
		}
		env.win = mlx_new_window(env.mlx, env.width, env.height, "Gros PD de TITRE DE MERDE!!");
		env.img = mlx_new_image(env.mlx, env.width_img, env.height_img);
		env.char_img = mlx_get_data_addr(env.img, &env.bbp, &env.size_line, &env.endian);

		mlx_key_hook(env.win, key_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_putendl("Le programme a besoin que d'un seul argument");
	return (0);
}
