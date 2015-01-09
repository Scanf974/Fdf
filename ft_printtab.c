/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 18:55:09 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 09:37:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define P_X
#define P_Y
#define P_Z

void	ft_printtab(t_env *env, char type)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (type == ORI_TAB)
	{
		ft_putendl("VOICI la tabe a l'origine");
		while (env->tab_origin[i])
		{
			j = 0;
			while (j < env->width_tab)
			{
#ifdef P_X
				if (env->tab_origin[i][j].x >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab_origin[i][j].x);
#endif
#ifdef P_Y
				if (env->tab_origin[i][j].y >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab_origin[i][j].y);
#endif
#ifdef P_Z
				if (env->tab_origin[i][j].z >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab_origin[i][j].z);
#endif
				ft_putchar('|');
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	else if (type == ISO_TAB)
	{
		while (env->tab[i])
		{
			j = 0;
			while (j < env->width_tab)
			{
#ifdef P_X
				if (env->tab[i][j].x >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab[i][j].x);
#endif
#ifdef P_Y
				if (env->tab[i][j].y >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab[i][j].y);
#endif
#ifdef P_Z
				if (env->tab[i][j].z >= 0)
					ft_putchar(' ');
				dprintf(1, "%.1f", env->tab[i][j].z);
#endif
				ft_putchar('|');
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
