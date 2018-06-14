/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 20:31:38 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 04:42:09 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len > size)
		return (src_len + size);
	i = 0;
	while (i + dest_len < size - 1 && src[i] != '\0')
	{
		*(dest + i + dest_len) = *(src + i);
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
