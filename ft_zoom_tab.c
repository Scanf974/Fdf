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

void	ft_zoom_tab(t_env *env, t_ptmax max, int zoom_it)
{
	unsigned int		i;
	unsigned int		j;

	if (zoom_it)
		env->padding = env->zoom / max.x;
	dprintf(1, "%f = %d / %f\n", env->padding, env->zoom, max.x);
	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			env->tab[i][j].x = env->tab[i][j].x * env->padding;
			env->tab[i][j].y = env->tab[i][j].y * env->padding;
			env->tab[i][j].z = env->tab[i][j].z;
			j++;
		}
		i++;
	}
}
