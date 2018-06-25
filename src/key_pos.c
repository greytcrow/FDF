/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_pos.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 15:04:44 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 15:04:44 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

void	hook_modify(int key, t_bresenparms *t)
{
	t->x += (key == 92) ? 5 : 0;
	t->x -= (key == 91) ? 5 : 0;
	t->y += (key == 88) ? 5 : 0;
	t->y -= (key == 87) ? 5 : 0;
	t->z += (key == 85) ? 5 : 0;
	t->z -= (key == 84) ? 5 : 0;
	t->xoffset -= (key == 123) ? 10 : 0;
	t->xoffset += (key == 124) ? 10 : 0;
	t->yoffset -= (key == 126) ? 10 : 0;
	t->yoffset += (key == 125) ? 10 : 0;
	t->extrusion += (key == 89) ? 1 : 0;
	t->extrusion -= (key == 83) ? 1 : 0;
}

int		hook_key(int key, t_bresenparms *t)
{
	t_map		space;
	t_transmap	proj;

	if (key == 53)
		exit(EXIT_SUCCESS);
	hook_modify(key, t);
	if (key == 92 || key == 91 || key == 87 || key == 88 || key == 85 ||
			key == 84 || key == 123 || key == 124 || key == 125 || key == 126
			|| key == 89 || key == 83)
	{
		mlx_clear_window(t->mlx_ptr, t->win_ptr);
		space = rotation_input(t->space, t);
		proj = projection(space, *t);
		displaymap(proj, *t);
		mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 15, 0xF0F0F0,
			"use numpad to rotate figure and mousewheel to zoom");
		ft_memdel((void **)&space.coord);
		ft_memdel((void **)&proj.coord2d);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_bresenparms *t)
{
	t_map		space;
	t_transmap	proj;

	(void)x;
	(void)y;
	if (button == 4)
	{
		if (t->zoom >= 10)
			t->zoom = 10;
		t->zoom++;
	}
	if (button == 5)
	{
		if (t->zoom > 1)
			t->zoom--;
	}
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	space = rotation_input(t->space, t);
	proj = projection(space, *t);
	displaymap(proj, *t);
	mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 15, 0xF0F0F0,
		"use numpad to rotate figure and mousewheel to zoom");
	ft_memdel((void **)&space.coord);
	ft_memdel((void **)&proj.coord2d);
	return (0);
}

int		is_directory(char *accessdir)
{
	int				fd;

	fd = open(accessdir, O_DIRECTORY);
	close(fd);
	return (fd);
}

int		count(char **tableau)
{
	int				i;

	i = 0;
	while (tableau[i])
		i++;
	return (i);
}
