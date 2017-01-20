/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:13:17 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:14:35 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

int			ft_count_list(t_list_line *list)
{
	t_list_line	*tmp;
	int			k;

	k = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		k++;
	}
	return (k + 1);
}

void		ft_print_list(t_list_line *list)
{
	t_list_line *tmp;

	tmp = list;
	printf("Strat List Line:\n");
	while (tmp != NULL)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

t_list_line	*ft_new_list(char *line)
{
	t_list_line *new;

	new = (t_list_line*)malloc(sizeof(t_list_line));
	new->line = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void		ft_add_list(t_list_line *list, char *line)
{
	t_list_line *tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_list(line);
}

t_list_line	*ft_to_list(int fd)
{
	t_list_line	*list;
	int			j;
	char		*line;

	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (j == 0)
			list = ft_new_list(line);
		else
			ft_add_list(list, line);
		j++;
	}
	return (list);
}
