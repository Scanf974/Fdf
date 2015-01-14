/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:03:45 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 22:39:53 by bsautron         ###   ########.fr       */
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

void	ft_achtagniquetamere_end(t_env *env, int i)
{
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
	size_t		i;
	size_t		j;
	int			fd;
	char		*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		env->tab_origin[i] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		env->tab[i] = (t_pt3d *)malloc(sizeof(t_pt3d) * (*col + 1));
		j = 0;
		while (j < *col)
		{
			while (*line == ' ')
				line++;
			ft_achtagniquetamere(env, i, j, line);
			line += ft_intlen(ft_atoi(line)) + 1;
			if (env->tab_origin[i][j].z < 0.0)
				line++;
			j++;
		}
		i++;
	}
	ft_achtagniquetamere_end(env, i);
}

void	ft_gettab(t_env *env, char *file, size_t *lin, size_t *col)
{
	int			fd;
	char		*line;

	*lin = 0;
	fd = open(file, O_RDONLY);
	*col = 0;
	while (get_next_line(fd, &line) > 0)
	{
		*col = ft_max(*col, ft_nbcol(line));
		*lin = *lin + 1;
	}
	close(fd);
	env->tab_origin = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	env->tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * (*lin + 1));
	ft_achtagfucklanorme(env, file, col);
}
