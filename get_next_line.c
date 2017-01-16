/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:40:48 by ionofrei          #+#    #+#             */
/*   Updated: 2016/12/03 17:05:32 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_line(t_line **cur, int fd)
{
	char	*ch;
	char	*str;
	int		n;

	ch = (char*)malloc(sizeof(char) * 2);
	n = read(fd, ch, 1);
	if (n == -1)
		return (-1);
	else if (n == 0)
		return (0);
	str = (char*)malloc(sizeof(char) * 2);
	while (n != 0 && ch[0] != '\n')
	{
		str = ft_strjoin(str, ch);
		n = read(fd, ch, 1);
	}
	(*cur)->line = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	(*cur)->line = ft_strdup(str);
	free(str);
	return (1);
}

int	ft_check_fd(t_line **list, t_line **cur, int fd)
{
	int ret;

	*cur = *list;
	while (!(*cur))
	{
		if ((*cur)->fd == fd)
		{
			ret = ft_get_line(cur, fd);
			if (ret == 0)
				return (0);
			else if (ret == -1)
				return (-1);
			return (1);
		}
		(*cur) = (*cur)->next;
	}
	*cur = (t_line*)malloc(sizeof(t_line));
	ret = ft_get_line(cur, fd);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	(*cur)->next = *list;
	*list = *cur;
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static t_line	*list;
	t_line			*cur;
	int				ret;

	if (fd < 0 || fd > 1024 || !line)
		return (-1);
	list = (t_line*)malloc(sizeof(t_line));
	cur = (t_line*)malloc(sizeof(t_line));
	ret = ft_check_fd(&list, &cur, fd);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	*line = ft_strdup(cur->line);
	return (1);
}
