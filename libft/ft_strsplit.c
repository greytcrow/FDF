/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 20:28:34 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 14:44:26 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	size_t		get_nb_word(char const *s, char c)
{
	size_t		n;
	size_t		i;

	i = 0;
	n = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			n++;
		i++;
	}
	if (s[i - 1] != c)
		n++;
	return (n);
}

static		void	feed_coord(char const *s, char c, size_t *coord)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	if (s[i] != c)
	{
		coord[n] = 0;
		n++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			coord[n++] = i;
		else if (s[i + 1] != c && s[i] == c)
			coord[n++] = i + 1;
		i++;
	}
	if (s[i - 1] != c)
		coord[n] = i - 1;
}

static	char		**empty_chain(char **split)
{
	split = (char **)ft_memalloc(sizeof(char *));
	return (split);
}

static	char		**full_chain(char const *s, char **split, size_t *coord,
	size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		split[i] = ft_strsub(s, coord[j], coord[j + 1] - coord[j] + 1);
		i++;
		j += 2;
	}
	split[n] = NULL;
	return (split);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		*coord;
	size_t		n;

	if (s == NULL)
		return (NULL);
	split = NULL;
	n = get_nb_word(s, c);
	if (n == 0)
		empty_chain(split);
	coord = (size_t *)malloc(sizeof(size_t) * (n * 2));
	if (coord == NULL)
		return (NULL);
	feed_coord(s, c, coord);
	split = (char **)ft_memalloc(sizeof(char *) * (n + 1));
	if (split == NULL)
		return (NULL);
	split[n] = NULL;
	full_chain(s, split, coord, n);
	ft_memdel((void **)&coord);
	return (split);
}
