/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 16:21:23 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 18:52:02 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	ad;

	ad = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ad = i;
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (ad < 0 ? NULL : (char *)&s[ad]);
}
