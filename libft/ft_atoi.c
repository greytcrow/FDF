/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:46:32 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 19:06:38 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t' || \
		*(s + i) == '\r' || *(s + i) == '\f' || *(s + i) == '\v')
		i++;
	if (*(s + i) == '-')
	{
		sign = -1;
		i++;
	}
	else if (*(s + i) == '+')
		i++;
	while (ft_isdigit(*(s + i)))
	{
		result = result * 10 + (*(s + i) - '0');
		i++;
	}
	return (result * sign);
}
