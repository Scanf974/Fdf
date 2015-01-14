/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 22:45:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 23:14:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

# define ORI_TAB	1
# define ISO_TAB	2
# define Y			0
# define X			1

typedef struct		s_pt2d
{
	float	x;
	float	y;
}					t_pt2d;

typedef struct		s_pt3d
{
	float	x;
	float	y;
	float	z;
}					t_pt3d;

typedef struct		s_ptmax
{
	float	x;
	float	y;
}					t_ptmax;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_pt3d			**tab_origin;
	t_pt3d			**tab;
	size_t			width_tab;
	size_t			height_tab;
	size_t			width;
	size_t			height;
	size_t			width_img;
	size_t			height_img;
	float			padding;
	t_pt2d			*origin_img;
	t_ptmax			memo;
	int				angle[3];
	float			**m;
	char			*char_img;
	void			*img;
	int				zoom;
	int				size_line;
	int				endian;
	int				bbp;
}					t_env;

int					expose_hook(t_env *env);
int					key_hook(int keycode, t_env *env);
float				ft_abs(float n);
int					ft_max(int n1, int n2);
float				ft_dtor(float degre);
void				ft_gettab(t_env *env, char *file, size_t *lin, size_t *col);
t_pt3d				ft_proj_iso(t_env *env, t_pt3d pt);
void				ft_proj_tab_iso(t_env *env);
t_ptmax				ft_regu_tab(t_env *env);
void				ft_zoom_tab(t_env *env, t_ptmax memo, int zoom_it);
void				ft_draw_line_in_image(t_env *env, t_pt3d pt0, t_pt3d pt1);
void				ft_make_draw(t_env *env);
void				ft_make_mx(float mx[3][3], t_env *env);
void				ft_make_my(float my[3][3], t_env *env);
void				ft_make_mz(float mz[3][3], t_env *env);
void				ft_white(int *b, int *g, int *r);
void				ft_north(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_east(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_west(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_east_north(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_east_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_north_east(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_north_west(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_south_east(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_south_west(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_west_north(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_west_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d);
void				ft_put_pixel_in_image(t_env *env, t_pt3d pt, float ez);

#endif
