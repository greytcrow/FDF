/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 17:04:45 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 04:49:03 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f) (char *))
{
	size_t	i;
	size_t	size;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		f(s + i);
		i++;
	}
}
