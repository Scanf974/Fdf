/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 09:24:12 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/02 22:40:32 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_tab(t_env *env, t_ptmax max)
{
	unsigned int		i;
	unsigned int		j;
	float	padding;

	padding = env->zoom / max.x;
	dprintf(1, "padding = %f\n", padding);
	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			env->tab[i][j].x = env->tab_origin[i][j].x * (float)padding;
			env->tab[i][j].y = env->tab_origin[i][j].y * (float)padding;
			env->tab[i][j].z = env->tab_origin[i][j].z;
			j++;
		}
		i++;
	}
}
