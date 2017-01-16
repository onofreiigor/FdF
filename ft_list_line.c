#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

int ft_count_list(td_list *list)
{
	td_list *tmp;
	int k;

	k = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		k++;
	}
	return (k + 1);
}

void	ft_print_list(td_list *list)
{
	td_list *tmp;

	tmp = list;
	printf("Strat List Line:\n");
	while (tmp != NULL)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

td_list *ft_new_list(char *line)
{
	td_list *new;

	new = (td_list*)malloc(sizeof(td_list));
	new->line = ft_strdup(line);
	new->next = NULL;

	return (new);
}

void	ft_add_list(td_list *list, char *line)
{
	td_list *tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_list(line);
}

td_list *ft_to_list(int fd)
{
	td_list *list;
	int j;
	char *line;

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