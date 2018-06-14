/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:35:02 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:21:16 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sbis;
	int		i;

	sbis = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (sbis == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(sbis + i) = *(s + i);
		i++;
	}
	*(sbis + i) = '\0';
	return (sbis);
}
