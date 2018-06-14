/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 16:22:27 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 02:57:00 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*usrc;
	unsigned char	*udest;
	unsigned int	uc;

	usrc = (unsigned char *)src;
	udest = (unsigned char *)dest;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		udest[i] = usrc[i];
		if (usrc[i] == uc)
			return (udest + i + 1);
		i++;
	}
	return (NULL);
}
