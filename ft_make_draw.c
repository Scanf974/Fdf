/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 04:29:53 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 05:10:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_draw(t_env *env)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < env->height_tab)
	{
		j = 0;
		while (j < env->width_tab)
		{
			if (env->tab[i][j + 1].x > 0)
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i][j + 1]);
			if (env->tab[i + 1])
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i + 1][j]);
			j++;
		}
		i++;
	}
}
