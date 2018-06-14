/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 19:22:36 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 03:47:33 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	src_len;

	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	str = ft_memalloc(src_len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s);
	i = 0;
	while (i < src_len)
	{
		*(str + i) = f(*(str + i));
		i++;
	}
	return (str);
}
