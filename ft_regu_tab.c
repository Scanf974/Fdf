/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regu_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:56:32 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 21:38:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_ptmax	ft_mini(t_env *env)
{
	unsigned int		i;
	unsigned int		j;
	t_ptmax				min;

	min.x = env->tab[0][0].x;
	min.y = env->tab[0][0].y;
	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			if (env->tab[i][j].x < min.x)
				min.x = env->tab[i][j].x;
			if (env->tab[i][j].y < min.y)
				min.y = env->tab[i][j].y;
			j++;
		}
		i++;
	}
	return (min);
}

t_ptmax			ft_regu_tab(t_env *env)
{
	unsigned int		i;
	unsigned int		j;
	t_ptmax				memo;
	t_ptmax				min;

	min = ft_mini(env);
	memo.x = env->tab[0][0].x;
	memo.y = env->tab[0][0].y;
	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			env->tab[i][j].x += ft_abs(min.x);
			env->tab[i][j].y += ft_abs(min.y);
			if (env->tab[i][j].x > memo.x)
				memo.x = env->tab[i][j].x;
			if (env->tab[i][j].y > memo.y)
				memo.y = env->tab[i][j].y;
			j++;
		}
		i++;
	}
	return (memo);
}
