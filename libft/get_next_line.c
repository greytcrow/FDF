/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:16:48 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 16:50:34 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_stock(int fd, char **buffer)
{
	char	*tmp;
	char	buf[BUFF_SIZE_GET + 1];
	int		ret;

	buf[BUFF_SIZE_GET] = '\0';
	ret = 0;
	while (!(ft_strchr(!(*buffer) ? "" : (*buffer), '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE_GET);
		buf[ret] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(!(*buffer) ? "" : (*buffer), buf);
		ft_memdel((void **)&tmp);
		if (ret == 0)
			return (0);
		if (ret < 0)
			return (-1);
	}
	if (ret <= 0)
		return (0);
	return (1);
}

int		ft_tmcr(char **line, char **buffer, int ret)
{
	int		i;
	char	*to_free;

	i = -1;
	while ((*buffer)[++i])
	{
		if ((*buffer)[i] == '\n')
		{
			to_free = *buffer;
			*line = ft_strsub(*buffer, 0, i);
			*buffer = ft_strsub(*buffer, i + 1, ft_strlen(*buffer) - (i + 1));
			ft_memdel((void **)&to_free);
			return (1);
		}
	}
	to_free = *buffer;
	*line = ft_strsub(*buffer, 0, i);
	*buffer = NULL;
	ft_memdel((void **)&to_free);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	int			read_return;

	if (line == NULL)
		return (-1);
	if (fd < 0)
		return (-1);
	read_return = 0;
	read_return = ft_stock(fd, &buffer);
	read_return = ft_tmcr(line, &buffer, read_return);
	if (read_return == -1)
		return (-1);
	if (*line[0] != '\0')
		return (1);
	return (read_return);
}
