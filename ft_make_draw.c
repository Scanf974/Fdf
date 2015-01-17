/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 04:29:53 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 15:08:34 by bsautron         ###   ########.fr       */
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
			if (j + 1 < env->width_tab)
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i][j + 1]);
			if (env->tab[i + 1])
				ft_draw_line_in_image(env, env->tab[i][j], env->tab[i + 1][j]);
			j++;
		}
		i++;
	}
}
