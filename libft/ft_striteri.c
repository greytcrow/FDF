/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 17:39:26 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 04:49:27 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	int i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		f(i, (s + i));
		i++;
	}
}
