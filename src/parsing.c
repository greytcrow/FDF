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

int			parseline(char *line, size_t *i, t_map *space, size_t y)
{
	size_t			x;
	char			**split;

	split = ft_strsplit(line, ' ');
	x = -1;
	if ((size_t)count(split) != space->width)
	{
		ft_display_error("line not correct size\n");
		exit(0);
	}
	while (++x < space->width)
	{
		space->coord[*i].vector3d[0] = (double)x;
		space->coord[*i].vector3d[1] = (double)y;
		space->coord[*i].vector3d[2] = ((double)ft_atoi(split[x]) * 0.1);
		++(*i);
	}
	x = -1;
	while (++x < space->width)
		ft_memdel((void **)&split[x]);
	ft_memdel((void **)&split);
	return (0);
}

void		fill_data(t_map *space, int fd)
{
	char			*line;
	size_t			num;
	size_t			i;

	num = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		parseline(line, &i, space, num);
		ft_memdel((void **)&line);
		num++;
	}
	ft_memdel((void **)&line);
	close(fd);
}

t_2dpoint	get_height_width(int fd)
{
	t_2dpoint		point;
	char			*line;
	char			**list;

	point.vector2d[0] = -1;
	point.vector2d[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		if (point.vector2d[0] == -1)
			point.vector2d[0] = count(list);
		else if (count(list) != point.vector2d[0])
		{
			point.vector2d[0] = -1;
			free_data(line, list);
			return (point);
		}
		point.vector2d[1]++;
		free_data(line, list);
	}
	ft_memdel((void **)&line);
	return (point);
}

int			parsing(int fd, t_map *space, char *file)
{
	t_2dpoint		point;
	int				fd2;

	point = get_height_width(fd);
	if (point.vector2d[0] == -1 || point.vector2d[0] == 0)
		return (0);
	space->height = (size_t)point.vector2d[1];
	space->width = (size_t)point.vector2d[0];
	space->coord = ft_memalloc(space->width * space->height * sizeof(t_point));
	close(fd);
	if ((fd2 = open(file, O_RDONLY)) < 0 || is_directory(file) != -1)
	{
		ft_display_error("invalid file descriptor\n");
		exit(EXIT_FAILURE);
	}
	fill_data(space, fd2);
	return (1);
}

t_map		mapcreation(int fd, char *string)
{
	t_map			space;

	if (!parsing(fd, &space, string))
	{
		ft_display_error("invalid map\n");
		exit(EXIT_FAILURE);
	}
	return (space);
}
