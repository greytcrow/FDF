/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 15:15:20 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 16:19:02 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i + ft_strlen(needle) <= len)
	{
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
