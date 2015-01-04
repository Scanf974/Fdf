/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_tab_iso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:50:37 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 09:48:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj_tab_iso(t_env *env)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (j < env->width_tab)
		{
			env->tab_origin[i][j] = ft_proj_iso(env->tab_origin[i][j]);
			j++;
		}
		i++;
	}
}
