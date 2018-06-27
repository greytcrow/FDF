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

#define IS_DEL(c, d) (c == d)

static int        count_words(const char *s, char delimiter)
{
	int i;
	int words;

	i = -1;
	words = 0;
	while (s[++i])
		if (((i != 0 && IS_DEL(s[i], delimiter) &&
			  !IS_DEL(s[i - 1], delimiter)) ||
			 (s[i + 1] == '\0' && !IS_DEL(s[i], delimiter))))
			words++;
	return (words);
}

static char        *get_word(const char *s, char delimiter)
{
	int        i;
	int        size;
	char    *word;

	i = -1;
	size = 0;
	while (s[++i] && !IS_DEL(s[i], delimiter))
		size++;
	word = ft_memalloc(sizeof(char) * (size + 1));
	word[size] = '\0';
	while (*s && !IS_DEL(*s, delimiter))
	{
		*word++ = *s;
		s++;
	}
	return (word - size);
}

char            **ft_strsplit(char const *s, char delimiter)
{
	int        size;
	char    **tab;
	char    *str;

	if (!s)
		return (NULL);
	size = count_words(s, delimiter);
	if (!(tab = ft_memalloc((size + 1) * sizeof(char*))))
		return (NULL);
	tab[size] = 0;
	str = (char *)s;
	while (*str)
	{
		if (!IS_DEL(*str, delimiter))
		{
			*tab++ = get_word(str, delimiter);
			str += ft_strlen(tab[-1]) - 1;
		}
		str++;
	}
	return (tab - size);
}