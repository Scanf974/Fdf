#include "fdf.h"

void	ft_north(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / -d[Y];
	ez = 2 * pt0.z;
	while (pt0.y > pt1.y)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.y--;
	}
}
