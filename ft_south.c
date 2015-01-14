/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_south.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:02:44 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 19:02:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / d[Y];
	ez = pt0.z;
	while (pt0.y < pt1.y)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y++;
	}
}
