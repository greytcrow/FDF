/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mult_matrix.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 19:17:46 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 19:17:46 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

t_matrix	mult_matrix(t_matrix aa, t_matrix bb)
{
	t_matrix	c;
	int			i;
	int			j;
	int			k;

	i = -1;
	j = -1;
	k = -1;
	ft_init_matrix(&c);
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
				c.matrix[j][i] += aa.matrix[k][i] * bb.matrix[j][k];
		}
		j = -1;
	}
	return (c);
}
