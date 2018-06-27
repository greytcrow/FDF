/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenhamdraw.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 12:48:43 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 18:19:18 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	derivate_init(t_bresenham *str, t_bresenparms p)
{
	str->dx = (int)fabs(p.x1 - p.x0);
	str->dy = (int)fabs(p.y1 - p.y0);
	str->sx = p.x0 < p.x1 ? 1 : -1;
	str->sy = p.y0 < p.y1 ? 1 : -1;
	str->err = (str->dx > str->dy ? str->dx : -(str->dy)) / 2;
}

void	bresenhamdraw(t_bresenparms p)
{
	unsigned int	i;
	t_bresenham		str;

	i = 0x59377C;
	derivate_init(&str, p);
	while (p.x0 != p.x1 || p.y0 != p.y1)
	{
		if (p.x0 >= 0 && p.y0 >= 0 && p.x0 < 2240 && p.y0 < 1310)
			mlx_pixel_put(p.mlx_ptr, p.win_ptr, (int)p.x0, (int)p.y0, i);
		str.e2 = str.err;
		if (str.e2 > -str.dx)
		{
			str.err -= str.dy;
			p.x0 += str.sx;
		}
		if (str.e2 < str.dy)
		{
			str.err += str.dx;
			p.y0 += str.sy;
		}
	}
}

void	usage_case(void)
{
	ft_putstr("Usage :  ./fdf name.fdf\n");
	exit(EXIT_FAILURE);
}

void	free_data(char *line,char **list)
{
	int				i;

	i = -1;
	while (list && list[++i])
		ft_memdel((void **)&list[i]);
	ft_memdel((void **)&list);
	ft_memdel((void **)&line);
}