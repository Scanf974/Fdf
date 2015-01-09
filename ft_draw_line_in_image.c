/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_in_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 19:53:22 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/02 23:27:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_in_image(t_env *env, t_pt3d pt0, t_pt3d pt1)
{
	float	d[2];

	d[X] = pt1.x - pt0.x;
	if (d[X] != 0.0)
	{
		if (d[X] > 0.0)
		{
			d[Y] = pt1.y - pt0.y;
			if (d[Y] != 0.0)
			{
				if (d[Y] > 0.0)
				{
					if (d[X] >= d[Y])
						ft_east_south(env, pt0, pt1, d);
					else
						ft_south_east(env, pt0, pt1, d);
				}
				else if (d[Y] < 0.0)
				{
					if (d[X] >= -d[Y])
						ft_east_north(env, pt0, pt1, d);
					else
						ft_north_east(env, pt0, pt1, d);
				}
			}
			else if (d[Y] == 0.0)
				ft_east(env, pt0, pt1, d);
		}
		else if (d[X] < 0.0)
		{
			d[Y] = pt1.y - pt0.y;
			if (d[Y] != 0.0)
			{
				if (d[Y] > 0.0)
				{
					if (-d[X] >= d[Y])
						ft_west_south(env, pt0, pt1, d);
					else
						ft_south_west(env, pt0, pt1, d);
				}
				else if (d[Y] < 0.0)
				{
					if (d[X] <= d[Y])
						ft_north_west(env, pt0, pt1, d);
					else
						ft_west_north(env, pt0, pt1, d);
				}
			}
			else if (d[Y] == 0.0)
				ft_west(env, pt0, pt1, d);
		}
	}
	else
	{
		d[Y] = pt1.y - pt0.y;
		if (d[Y] != 0.0)
		{
			if (d[Y] > 0.0)
				ft_south(env, pt0, pt1, d);
			else if (d[Y] < 0.0)
				ft_north(env, pt0, pt1, d);
		}
	}
}
