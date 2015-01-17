/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:12:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 15:37:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_mx(float mx[3][3], t_env *env)
{
	mx[0][0] = 1;
	mx[0][1] = 0;
	mx[0][2] = 0;
	mx[1][0] = 0;
	mx[1][1] = cos(ft_dtor(env->angle[0]));
	mx[1][2] = -sin(ft_dtor(env->angle[0]));
	mx[2][0] = 0;
	mx[2][1] = sin(ft_dtor(env->angle[0]));
	mx[2][2] = cos(ft_dtor(env->angle[0]));
}
