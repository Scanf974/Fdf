/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:52:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 18:22:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	**ft_init(void)
{
	float	**md;

	md = (float **)malloc(sizeof(float *) * 3);
	md[0] = (float *)malloc(sizeof(float) * 3);
	md[1] = (float *)malloc(sizeof(float) * 3);
	md[2] = (float *)malloc(sizeof(float) * 3);
	return (md);
}

static float	**ft_prod_mat33(float mx[3][3], float my[3][3], float mz[3][3])
{
	float	**md;
	float	mt[3][3];

	md = ft_init();
	mt[0][0] = mx[0][0] * my[0][0] + mx[0][1] * my[1][0] + mx[0][2] * my[2][0];
	mt[0][1] = mx[0][0] * my[0][1] + mx[0][1] * my[1][1] + mx[0][2] * my[2][1];
	mt[0][2] = mx[0][0] * my[0][2] + mx[0][1] * my[1][2] + mx[0][2] * my[2][2];
	mt[1][0] = mx[1][0] * my[0][0] + mx[1][1] * my[1][0] + mx[1][2] * my[2][0];
	mt[1][1] = mx[1][0] * my[0][1] + mx[1][1] * my[1][1] + mx[1][2] * my[2][1];
	mt[1][2] = mx[1][0] * my[0][2] + mx[1][1] * my[1][2] + mx[1][2] * my[2][2];
	mt[2][0] = mx[2][0] * my[0][0] + mx[2][1] * my[1][0] + mx[2][2] * my[2][0];
	mt[2][1] = mx[2][0] * my[0][1] + mx[2][1] * my[1][1] + mx[2][2] * my[2][1];
	mt[2][2] = mx[2][0] * my[0][2] + mx[2][1] * my[1][2] + mx[2][2] * my[2][2];
	md[0][0] = mt[0][0] * mz[0][0] + mt[0][1] * mz[1][0] + mt[0][2] * mz[2][0];
	md[0][1] = mt[0][0] * mz[0][1] + mt[0][1] * mz[1][1] + mt[0][2] * mz[2][1];
	md[0][2] = mt[0][0] * mz[0][2] + mt[0][1] * mz[1][2] + mt[0][2] * mz[2][2];
	md[1][0] = mt[1][0] * mz[0][0] + mt[1][1] * mz[1][0] + mt[1][2] * mz[2][0];
	md[1][1] = mt[1][0] * mz[0][1] + mt[1][1] * mz[1][1] + mt[1][2] * mz[2][1];
	md[1][2] = mt[1][0] * mz[0][2] + mt[1][1] * mz[1][2] + mt[1][2] * mz[2][2];
	md[2][0] = mt[2][0] * mz[0][0] + mt[2][1] * mz[1][0] + mt[2][2] * mz[2][0];
	md[2][1] = mt[2][0] * mz[0][1] + mt[2][1] * mz[1][1] + mt[2][2] * mz[2][1];
	md[2][2] = mt[2][0] * mz[0][2] + mt[2][1] * mz[1][2] + mt[2][2] * mz[2][2];
	return (md);
}

static t_pt3d	ft_prod_mat31(float **mat, t_pt3d pt)
{
	t_pt3d	pt_ret;

	pt_ret.x = pt.x * (mat[0][0] + mat[0][1] + mat[0][2]);
	pt_ret.y = pt.y * (mat[1][0] + mat[1][1] + mat[1][2]);
	pt_ret.z = pt.z * (mat[2][0] + mat[2][1] + mat[2][2]);
	return (pt_ret);
}

t_pt3d			ft_proj_iso(t_env *env, t_pt3d pt)
{
	t_pt3d		pt_iso;
	t_pt3d		pt_rot;
	float		mx[3][3];
	float		my[3][3];
	float		mz[3][3];

	ft_make_mx(mx, env);
	ft_make_my(my, env);
	ft_make_mz(mz, env);
	env->m = ft_prod_mat33(mx, my, mz);
	pt_rot = ft_prod_mat31(env->m, pt);
	pt_iso.x = pt_rot.x + pt_rot.y;
	pt_iso.y = 0.5 * (pt_rot.y - pt_rot.x) - pt_rot.z * 0.14;
	pt_iso.z = pt.z;
	return (pt_iso);
}
