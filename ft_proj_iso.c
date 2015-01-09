/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 08:52:00 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 06:47:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	**ft_prod_mat33(float mx[3][3], float my[3][3], float mz[3][3])
{
	float	**md;
	float	mt[3][3];

	md = (float **)malloc(sizeof(float *) * 3);
	md[0] = (float *)malloc(sizeof(float) * 3);
	md[1] = (float *)malloc(sizeof(float) * 3);
	md[2] = (float *)malloc(sizeof(float) * 3);
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

static float	ft_dtor(float degre)
{
	return (3.14159 * degre / 180);
}

t_pt3d	ft_proj_iso(t_env *env, t_pt3d pt)
{
	t_pt3d		pt_iso;
	t_pt3d		pt_rot;
	float		cte1;
	float		cte2;
	float		mx[3][3];
	float		my[3][3];
	float		mz[3][3];

	mx[0][0] = 1;
	mx[0][1] = 0;
	mx[0][2] = 0;
	mx[1][0] = 0;
	mx[1][1] = cos(ft_dtor(env->angle[0]));
	mx[1][2] = -sin(ft_dtor(env->angle[0]));
	mx[2][0] = 0;
	mx[2][1] = sin(ft_dtor(env->angle[0]));
	mx[2][2] = cos(ft_dtor(env->angle[0]));

	my[0][0] = cos(ft_dtor(env->angle[1]));
	my[0][1] = 0;
	my[0][2] = sin(ft_dtor(env->angle[1]));
	my[1][0] = 0;
	my[1][1] = 1;
	my[1][2] = 0;
	my[2][0] = -sin(ft_dtor(env->angle[1]));
	my[2][1] = 0;
	my[2][2] = cos(ft_dtor(env->angle[1]));

	mz[0][0] = cos(ft_dtor(env->angle[2]));
	mz[0][1] = -sin(ft_dtor(env->angle[2]));
	mz[0][2] = 0;
	mz[1][0] = sin(ft_dtor(env->angle[2]));
	mz[1][1] = cos(ft_dtor(env->angle[2]));
	mz[1][2] = 0;
	mz[2][0] = 0;
	mz[2][1] = 0;
	mz[2][2] = 1;

	env->m = ft_prod_mat33(mx, my, mz);
	pt_rot = ft_prod_mat31(env->m, pt);

	cte1 = 1.0;
	cte2 = 1.0;
	pt_iso.x = pt_rot.x * cte1 + pt_rot.y * cte2;
	pt_iso.y = 0.5 * (pt_rot.y * cte2 - pt_rot.x * cte1) - pt_rot.z * 0.14;
	pt_iso.z = pt.z;
	return (pt_iso);
}
