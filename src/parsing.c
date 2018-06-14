/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parcing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 17:45:02 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 17:45:03 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include <stdio.h>

void	print_data(double *data, int data_len)
{
	int i = 0;

	while(i < data_len)
	{
		printf("%d ",(int)data[i]);
		i++;
	}
	printf("\n");
}

int		parseline(char *line, size_t len_line, double **data)
{
	size_t			k;
	char			**split;

	split = ft_strsplit(line, ' ');
	k = -1;
	if ((size_t)ft_count(split) != len_line)
	{
		ft_display_error("line not correct size\n");
		exit(0);
	}
	*data = ft_memalloc(len_line * sizeof(double));
	while (++k < len_line)
	{
		(*data)[k] = ft_atoi(split[k]);
		ft_memdel((void **)&split[k]);
	}
	ft_memdel((void **)&split);
	return (0);
}

size_t	sizeofdata(char *line)
{
	size_t			i;
	char			**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		ft_memdel((void **)&tmp[i]);
		i++;
	}
	ft_memdel((void **)&tmp);
	return (i);
}


int		parsing(int fd, t_transition *premap)
{
	char			*line;

	get_next_line(fd, &line);
	premap->nb_col = sizeofdata(line);
	premap->data_len = premap->nb_col;
	premap->data = ft_memalloc(premap->data_len * sizeof(double *));
	parseline(line, premap->nb_col, premap->data);
	ft_memdel((void **)&line);
	premap->nb_line = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (premap->nb_line == premap->data_len)
		{
			premap->data = (double**)ft_realloc(premap->data, premap->data_len *
					sizeof(double *), premap->data_len * 2 * sizeof(double *));
			premap->data_len *= 2;
		}
		parseline(line, premap->nb_col, premap->data + premap->nb_line);
		premap->nb_line++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	return(0);
}

t_map	translation(t_transition premap)
{
	t_map			space;
	size_t			i;
	size_t			j;
	size_t			k;

	i = -1;
	j = -1;
	k = 0;
	space.width = premap.nb_col;
	space.height = premap.nb_line;
	space.coord = ft_memalloc((size_t)(space.height *
			space.width * sizeof(t_point)));
	while (++i < space.height)
	{
		while (++j < space.width)
		{
			space.coord[k].vector3d[0] = (double)j;
			space.coord[k].vector3d[1] = (double)i;
			space.coord[k].vector3d[2] = -premap.data[i][j] * 0.1;
			k++;
		}
		j = -1;
	}
	return (space);
}

t_map	mapcreation(int fd)
{
	t_transition	data;
	t_map			space;
	int				i;

	i = 0;
	parsing(fd, &data);
	space = translation(data);
	while (data.data[i])
	{
//		print_data(*data, len_line);
		ft_memdel((void **)&data.data[i]);
		i++;
	}
	if (!data.data)
		ft_memdel((void **)&data.data);
	return (space);
}
