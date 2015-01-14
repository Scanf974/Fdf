/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_in_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:10:07 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 04:28:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_lvl0(int *b, int *g, int *r, float ez)
{
	*b = 152 + ez * 0.8;
	if (*b <= 0)
		*b = 0;
	*g = 0;
	*r = 0;
}

static void	ft_lvl1(int *b, int *g, int *r, float ez)
{
	*b = 0;
	*g = 204 + ez;
	*r = 255;
}

static void	ft_lvl2(int *b, int *g, int *r, float ez)
{
	*b = 0;
	*g = 120 - ez * 1.5;
	*r = 0;
}

static void	ft_lvl3(int *b, int *g, int *r, float ez)
{
	*b = 1 + ez * 0.052;
	*g = 70 - ez * 0.014;
	*r = 101 + ez * 0.37;
}

void		ft_put_pixel_in_image(t_env *env, t_pt3d pt, float ez)
{
	int		the_p;
	int		r[1];
	int		g[1];
	int		b[1];

	ft_white(b, g, r);
	if (ez <= 0)
		ft_lvl0(b, g, r, ez);
	else if (ez <= 1)
		ft_lvl1(b, g, r, ez);
	else if (ez <= 50)
		ft_lvl2(b, g, r, ez);
	else if (ez <= 150)
		ft_lvl3(b, g, r, ez);
	if (((int)pt.x + env->origin_img->x) * 4 < env->size_line
			&& ((int)pt.x + env->origin_img->x) * 4 > 0
			&& ((int)pt.y + env->origin_img->y) * 4 < (int)env->height_img * 4
			&& ((int)pt.y + env->origin_img->y) * 4 > 0)
	{
		the_p = ((int)pt.x + env->origin_img->x) * 4;
		the_p += ((int)pt.y + env->origin_img->y) * env->size_line;
		env->char_img[the_p + 0] = *b;
		env->char_img[the_p + 1] = *g;
		env->char_img[the_p + 2] = *r;
	}
}
