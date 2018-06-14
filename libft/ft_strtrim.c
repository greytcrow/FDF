/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 17:31:50 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 03:51:18 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	start;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i++;
	if (!(s[i]))
		return (ft_strnew(0));
	start = i;
	i = 1;
	while (s[len - i] == ' ' || s[len - i] == '\t' || s[len - i] == '\n')
		i++;
	str = ft_strsub(s, (unsigned int)start, (len - i - start + 1));
	if (str == NULL)
		return (NULL);
	str[len - i - start + 1] = '\0';
	return (str);
}
