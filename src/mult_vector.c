/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mult_vector.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 16:25:28 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 16:25:28 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

t_point		mult_vector(t_matrix a, t_point b)
{
	int		i;
	int		j;
	t_point	c;

	i = -1;
	j = -1;
	init_vector(&c);
	while (++i < 3)
	{
		while (++j < 3)
			c.vector3d[i] += a.matrix[i][j] * b.vector3d[j];
		j = -1;
	}
	return (c);
}
