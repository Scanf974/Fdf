/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:28:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 20:30:35 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_mz(float mz[3][3], t_env *env)
{
	mz[0][0] = cos(ft_dtor(env->angle[2]));
	mz[0][1] = -sin(ft_dtor(env->angle[2]));
	mz[0][2] = 0;
	mz[1][0] = sin(ft_dtor(env->angle[2]));
	mz[1][1] = cos(ft_dtor(env->angle[2]));
	mz[1][2] = 0;
	mz[2][0] = 0;
	mz[2][1] = 0;
	mz[2][2] = 1;
}
