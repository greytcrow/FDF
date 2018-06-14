/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   spacerotation.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 18:21:46 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/25 15:04:28 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

t_point	ft_pointrotation(t_point point, double angle, char axis, t_point centre)
{
	t_point		pointprime;
	t_point		vector;
	t_point		vectorprime;

	vector.vector3d[0] = point.vector3d[0] - centre.vector3d[0];
	vector.vector3d[1] = point.vector3d[1] - centre.vector3d[1];
	vector.vector3d[2] = point.vector3d[2];
	if (axis == 'x')
		vectorprime = xvectorrotation(vector, angle);
	else if (axis == 'y')
		vectorprime = yvectorrotation(vector, angle);
	else
		vectorprime = zvectorrotation(vector, angle);
	pointprime.vector3d[0] = vectorprime.vector3d[0] + centre.vector3d[0];
	pointprime.vector3d[1] = vectorprime.vector3d[1] + centre.vector3d[1];
	pointprime.vector3d[2] = vectorprime.vector3d[2];
	return (pointprime);
}

t_map	spacerotation(t_map space, double angle, char axis)
{
	t_map		spaceprime;
	size_t		i;
	t_point		centre;

	spaceprime.height = space.height;
	spaceprime.width = space.width;
	centre.vector3d[0] = space.width / 2;
	centre.vector3d[1] = space.height / 2;
	centre.vector3d[2] = 0;
	i = 0;
	spaceprime.coord = ft_memalloc(space.height * space.width *
										sizeof(t_point));
	while (i < spaceprime.width * spaceprime.height)
	{
		spaceprime.coord[i] = ft_pointrotation(space.coord[i], angle,
											axis, centre);
		i++;
	}
	return (spaceprime);
}
