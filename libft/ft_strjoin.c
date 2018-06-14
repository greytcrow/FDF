/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 18:25:11 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 04:56:26 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s))
		return (NULL);
	while (s1[j])
	{
		*(s + i) = *(s1 + j);
		i++;
		j++;
	}
	j = -1;
	while (s2[++j])
	{
		*(s + i) = *(s2 + j);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
