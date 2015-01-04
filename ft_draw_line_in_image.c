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
#include <stdio.h> ///// PQS DE PRINTF

void	ft_put_pixel_in_image(t_env *env, t_pt3d pt, float ez)
{
	int		the_p;
	int		r;
	int		g;
	int		b;

	if (ez <= -20) // mer
	{
		b = 152;
		g = 0;
		r = 0;
	}
	else if (ez <= 1) // sable
	{
		b = 0;
		g = 204 + ez;
		r = 255;
	}
	else if (ez <= 50) // foret
	{
		b = 0;
		g = 120 - ez * 1.5;
		r = 0;
	}
	else if (ez <= 250) // terre
	{
		b = 1;
		g = 70;
		r = 101;
	}
	else //neige
	{
		b = 255;
		g = 255;
		r = 255;
	}


	if (((int)pt.x + env->origin_img->x) * 4 < env->size_line && ((int)pt.x + env->origin_img->x) * 4 > 0 &&
			((int)pt.y + env->origin_img->y) * 4 < (int)env->height_img * 4 && ((int)pt.y + env->origin_img->y) * 4 > 0)
	{
		the_p = ((int)pt.x + env->origin_img->x) * 4 + ((int)pt.y + env->origin_img->y) * env->size_line;
		env->char_img[the_p + 0] = b;
		env->char_img[the_p + 1] = g;
		env->char_img[the_p + 2] = r;
	}
	(void)ez;
}

void	ft_draw_line_in_image(t_env *env, t_pt3d pt0, t_pt3d pt1)
{
	float	e;
	float	dx;
	float	dy;
	float	ez;
	float	ht;

	dx = pt1.x - pt0.x;
	ht = (pt1.z - pt0.z) / dx;
	ez = 2 * pt0.z;
	if (dx != 0.0)
	{
		if (dx > 0.0)
		{
			dy = pt1.y - pt0.y;
			if (dy != 0.0)
			{
				if (dy > 0.0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.x += 1;
							if (pt0.x >= pt1.x)
								break ;
							e -= dy;
							if (e < 0.0)
							{
								pt0.y += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.y += 1;
							if (pt0.y >= pt1.y)
								break ;
							e -= dx;
							if (e < 0.0)
							{
								pt0.x += 1;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0.0)
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						ez = pt0.z;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.x += 1;
							if (pt0.x >= pt1.x)
								break ;
							e += dy;
							if (e < 0.0)
							{
								pt0.y -= 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.y -= 1.0;
							if (pt0.y <= pt1.y)
								break ;
							e += dx;
							if (e > 0.0)
							{
								pt0.x += 1;
								e += dy;
							}
						}
					}
				}
			}
			else if (dy == 0.0)
			{
				while (pt0.x < pt1.x)
				{
					ft_put_pixel_in_image(env, pt0, ez);
					ez += ht;
					pt0.x++;
				}
			}
		}
		else if (dx < 0.0)
		{
			dy = pt1.y - pt0.y;
			if (dy != 0.0)
			{
				if (dy > 0.0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.x -= 1;
							if (pt0.x <= pt1.x)
								break ;
							e += dy;
							if (e >= 0.0)
							{
								pt0.y += 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.y += 1;
							if (pt0.y >= pt1.y)
								break ;
							e += dx;
							if (e <= 0.0)
							{
								pt0.x -= 1;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0.0)
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.x -= 1;
							if (pt0.x <= pt1.x)
								break ;
							e -= dy;
							if (e >= 0.0)
							{
								pt0.y -= 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							ft_put_pixel_in_image(env, pt0, ez);
							ez += ht;
							pt0.y -= 1;
							if (pt0.y <= pt1.y)
								break ;
							e -= dx;
							if (e >= 0.0)
							{
								pt0.x -= 1;
								e += dy;
							}
						}
					}
				}
			}
			else if (dy == 0.0)
			{
				while (pt0.x > pt1.x)
				{
					ft_put_pixel_in_image(env, pt0, ez);
					ez += ht;
					pt0.x--;
				}
			}
		}
	}
	else
	{
		dy = pt1.y - pt0.y;
		if (dy != 0.0)
		{
			if (dy > 0.0)
			{
				while (pt0.y < pt1.y)
				{
					ft_put_pixel_in_image(env, pt0, ez);
					ez += ht;
					pt0.y++;
				}
			}
			else if (dy < 0.0)
			{
				while (pt0.y > pt1.y)
				{
					ft_put_pixel_in_image(env, pt0, ez);
					ez += ht;
					pt0.y--;
				}
			}
		}
	}
}
