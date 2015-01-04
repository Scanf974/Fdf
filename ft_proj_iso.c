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

t_pt3d	ft_proj_iso(t_pt3d pt)
{
	t_pt3d		pt_ret;
	float		cte1;
	float		cte2;

	cte1 = 1.0;
	cte2 = 1.0;
	pt_ret.x = pt.x * cte1 + pt.y * cte2;
	pt_ret.y = 0.5 * (pt.y * cte2 - pt.x * cte1) - pt.z * 0.14;
	pt_ret.z = pt.z;
	//dprintf(1, "x = %f, y = %f\n", pt_ret.x, pt_ret.y);
	return (pt_ret);
}
