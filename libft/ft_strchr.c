/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 15:08:18 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 16:06:37 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char *)(s + i));
}
