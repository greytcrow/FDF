/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 14:43:01 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 19:44:49 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include <stdio.h>

size_t	space_gain(t_bresenparms p, t_transmap map2d, size_t i, size_t max)
{
	size_t			j;

	j = max - map2d.width;
	while (j < max)
	{
		if (j + 1 != max)
		{
			p.y0 = map2d.coord2d[j].vector2d[1];
			p.y1 = map2d.coord2d[j + 1].vector2d[1];
			p.x0 = map2d.coord2d[j].vector2d[0];
			p.x1 = map2d.coord2d[j + 1].vector2d[0];
			bresenhamdraw(p);
		}
		if (i + 1 != map2d.height)
		{
			p.y0 = map2d.coord2d[j].vector2d[1];
			p.y1 = map2d.coord2d[j + map2d.width].vector2d[1];
			p.x0 = map2d.coord2d[j].vector2d[0];
			p.x1 = map2d.coord2d[j + map2d.width].vector2d[0];
			bresenhamdraw(p);
		}
		j++;
	}
	max += map2d.width;
	return (max);
}

int		displaymap(t_transmap map2d, t_bresenparms p)
{
	size_t			i;
	size_t			max;

	p.widthmax = (int)map2d.width * 100;
	p.heightmax = (int)map2d.height * 100;
	i = 0;
	max = map2d.width;
	while (i < map2d.height)
	{
		max = space_gain(p, map2d, i, max);
		i++;
	}
	return (1);
}

t_map	rotation_input(t_map space, t_bresenparms *t)
{
	t_map	spacedash;
	t_map	intermspace1;
	t_map	intermspace2;

	intermspace1 = spacerotation(space, t->x * M_PI / 180, 'x');
	intermspace2 = spacerotation(intermspace1, t->y * M_PI / 180, 'y');
	spacedash = spacerotation(intermspace2, t->z * M_PI / 180, 'z');
	ft_memdel((void **)&intermspace1.coord);
	ft_memdel((void **)&intermspace2.coord);
	return (spacedash);
}

void	init_struct(t_bresenparms *p)
{
	p->x = 240;
	p->y = 200;
	p->z = 220;
	p->zoom = 2;
	p->xoffset = 0;
	p->yoffset = 0;
	p->extrusion = 0;
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, 2240, 1310, "mlx 42");
}

int		main(int argc, char **argv)
{
	int				fd;
	t_transmap		twodmap;
	t_bresenparms	p;
	t_map			spacedash;

	if (argc == 1)
		usage_case();
	if ((fd = open(argv[1], O_RDONLY)) < 0 || is_directory(argv[1]) != -1 ||
		argc > 2)
	{
		ft_display_error("invalid file descriptor\n");
		exit(EXIT_FAILURE);
	}
	p.space = mapcreation(fd, argv[1]);
	init_struct(&p);
	spacedash = rotation_input(p.space, &p);
	twodmap = projection(spacedash, p);
	displaymap(twodmap, p);
	ft_memdel((void **)&spacedash.coord);
	mlx_string_put(p.mlx_ptr, p.win_ptr, 10, 15, 255, "use numpad/mousewheel");
	mlx_mouse_hook(p.win_ptr, mouse_hook, &p);
	mlx_hook(p.win_ptr, 2, 1L, hook_key, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
