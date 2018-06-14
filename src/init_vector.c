/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_vector.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 16:51:04 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 16:51:04 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

void	init_vector(t_point *a)
{
	a->vector3d[0] = 0;
	a->vector3d[1] = 0;
	a->vector3d[2] = 0;
}
