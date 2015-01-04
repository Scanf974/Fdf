/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regu_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:56:32 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 09:47:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptmax	ft_regu_tab(t_env *env)
{
	float	minx;
	float	miny;
	unsigned int		i;
	unsigned int		j;
	t_ptmax	memo;

	minx = env->tab_origin[0][0].x;
	miny = env->tab_origin[0][0].y;
	memo.x = env->tab_origin[0][0].x;
	memo.y = env->tab_origin[0][0].y;
	i = 0;
	while (env->tab_origin[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			if (env->tab_origin[i][j].x < minx)
				minx = env->tab_origin[i][j].x;
			if (env->tab_origin[i][j].y < miny)
				miny = env->tab_origin[i][j].y;
			j++;
		}
		i++;
	}
	i = 0;
	while (env->tab_origin[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			env->tab_origin[i][j].x += ft_abs(minx);
			env->tab_origin[i][j].y += ft_abs(miny);
			if (env->tab_origin[i][j].x > memo.x)
				memo.x = env->tab_origin[i][j].x;
			if (env->tab_origin[i][j].y > memo.y)
				memo.y = env->tab_origin[i][j].y;
			j++;
		}
		i++;
	}
	return (memo);
}
