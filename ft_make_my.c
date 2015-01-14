/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_my.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:27:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 20:34:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_my(float my[3][3], t_env *env)
{
	my[0][0] = cos(ft_dtor(env->angle[1]));
	my[0][1] = 0;
	my[0][2] = sin(ft_dtor(env->angle[1]));
	my[1][0] = 0;
	my[1][1] = 1;
	my[1][2] = 0;
	my[2][0] = -sin(ft_dtor(env->angle[1]));
	my[2][1] = 0;
	my[2][2] = cos(ft_dtor(env->angle[1]));
}
