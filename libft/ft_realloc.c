/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 17:40:36 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:40:36 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t oldsize, size_t newsize)
{
	void *new;

	if (newsize < 1 || newsize < oldsize)
		return (NULL);
	new = ft_memalloc(newsize);
	ft_memcpy(new, old, oldsize);
	ft_memdel(&old);
	return (new);
}
