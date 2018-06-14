/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:26:57 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 04:39:20 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *udest;
	unsigned char *usrc;

	usrc = (unsigned char *)src;
	udest = (unsigned char *)dest;
	if (usrc <= udest)
	{
		udest += n - 1;
		usrc += n - 1;
		while (n--)
		{
			*udest-- = *usrc--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
