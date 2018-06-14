/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 20:54:23 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:38:07 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*r;
	int		i;

	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	while (i < (int)ft_strlen(s) - 1)
	{
		*(r + i) = *(s + ft_strlen(s) + i);
		i++;
	}
	*(r + i) = '\0';
	return (r);
}
