/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 16:33:58 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:19:09 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n2)
{
	char		*s;
	int			i;
	long int	n;

	if (n2 == 0)
		return (ft_strdup("0"));
	n = (long)n2;
	i = ft_count_digit(n);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[i] = '\0';
	i--;
	while (n)
	{
		*(s + i) = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
