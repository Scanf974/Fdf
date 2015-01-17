/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:03:45 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 18:20:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_nbcol(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] > ' ' && str[i + 1] <= ' ')
			nb++;
		i++;
	}
	return (nb);
}

void	ft_achtagniquetamere_end(t_env *env, int i, int fd)
{
	close(fd);
	env->tab_origin[i] = NULL;
	env->tab[i] = NULL;
}

void	ft_achtagniquetamere(t_env *env, int i, int j, char *line)
{
	env->tab_origin[i][j].y = (float)i;
	env->tab_origin[i][j].x = (float)j;
	env->tab_origin[i][j].z = (float)ft_atoi(line);
}

void	ft_achtagfucklanorme(t_env *env, char *file, size_t *col)
{
	size_t		ijk[3];
	int			fd;
	char		*line;

	ijk[0] = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		env->tab_origin[ijk[0]] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		env->tab[ijk[0]] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		FUCK_Y;
		while (ijk[1] < *col)
		{
			while (line[ijk[2]] &&
					!ft_isdigit(line[ijk[2]]) && line[ijk[2]] != '-')
				ijk[2]++;
			ft_achtagniquetamere(env, ijk[0], ijk[1], &line[ijk[2]]);
			ijk[2] += ft_intlen(ft_atoi(&line[ijk[2]])) + 1;
			if (env->tab_origin[ijk[0]][ijk[1]].z < 0.0)
				ijk[2]++;
			ijk[1]++;
		}
		ijk[0]++;
	}
	ft_achtagniquetamere_end(env, ijk[0], fd);
}

void	ft_gettab(t_env *env, char *file, size_t *lin, size_t *col)
{
	int			fd;
	char		*line;
	int			ret;

	*lin = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("ARGV is not a file", 2);
		exit(1);
	}
	*col = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		*col = ft_max(*col, ft_nbcol(line));
		*lin = *lin + 1;
	}
	if (ret == -1)
	{
		ft_putendl_fd("ARGV is a Directory boy!", 2);
		exit(1);
	}
	close(fd);
	env->tab_origin = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	env->tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	ft_achtagfucklanorme(env, file, col);
}
