/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 12:05:27 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 18:11:58 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

t_2dpoint	pointproject(t_point point3d, t_bresenparms p)
{
	t_2dpoint	point2d;

	point2d.vector2d[0] = (int)(point3d.vector3d[0] * 20 +
								point3d.vector3d[2] + p.xoffset);
	point2d.vector2d[1] = (int)(point3d.vector3d[1] * 20 +
								point3d.vector3d[2] + p.yoffset);
	point2d.vector2d[0] *= p.zoom;
	point2d.vector2d[1] *= p.zoom;
	return (point2d);
}

t_transmap	projection(t_map threed, t_bresenparms p)
{
	t_transmap	twod;
	size_t		i;

	i = 0;
	twod.height = (int)threed.height;
	twod.width = (int)threed.width;
	twod.coord2d = ft_memalloc(twod.height * twod.width * sizeof(t_2dpoint));
	while (i < twod.width * twod.height)
	{
		twod.coord2d[i] = pointproject(threed.coord[i], p);
		i++;
	}
	return (twod);
}
