/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zrotation.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 14:42:08 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/25 15:03:01 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

t_matrix		zrotation(t_matrix a, double angle)
{
	t_matrix	b;

	b.matrix[0][0] = cos(angle);
	b.matrix[0][1] = -sin(angle);
	b.matrix[0][2] = 0;
	b.matrix[1][0] = sin(angle);
	b.matrix[1][1] = cos(angle);
	b.matrix[1][2] = 0;
	b.matrix[2][0] = 0;
	b.matrix[2][1] = 0;
	b.matrix[2][2] = 1;
	return (mult_matrix(b, a));
}
