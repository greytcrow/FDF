/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 14:07:51 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 03:47:58 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	src_len;

	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (!(str = ft_memalloc(src_len + 1)))
		return (NULL);
	ft_strcpy(str, s);
	i = 0;
	while (i < src_len)
	{
		*(str + i) = f(i, *(str + i));
		i++;
	}
	return (str);
}
