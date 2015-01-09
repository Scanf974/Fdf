#include "fdf.h"

void	ft_put_pixel_in_image(t_env *env, t_pt3d pt, float ez)
{
	int		the_p;
	int		r;
	int		g;
	int		b;

	if (ez <= -2)
	{
		b = 152 + ez * 0.5;
		if (b <= 0)
			b = 0;
		g = 0;
		r = 0;
	}
	else if (ez <= 1)
	{
		b = 0;
		g = 204 + ez;
		r = 255;
	}
	else if (ez <= 50)
	{
		b = 0;
		g = 120 - ez * 1.5;
		r = 0;
	}
	else if (ez <= 250)
	{
		b = 1 + ez * 0.052;
		g = 70 - ez * 0.014;
		r = 101 + ez * 0.37;
	}
	else
	{
		b = 255;
		g = 255;
		r = 255;
	}


	if (((int)pt.x + env->origin_img->x) * 4 < env->size_line
		&& ((int)pt.x + env->origin_img->x) * 4 > 0
		&& ((int)pt.y + env->origin_img->y) * 4 < (int)env->height_img * 4
		&& ((int)pt.y + env->origin_img->y) * 4 > 0)
	{
		the_p = ((int)pt.x + env->origin_img->x) * 4;
		the_p += ((int)pt.y + env->origin_img->y) * env->size_line;
		env->char_img[the_p + 0] = b;
		env->char_img[the_p + 1] = g;
		env->char_img[the_p + 2] = r;
	}
}
