#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_print_arr(int **ar)
{
	int w;
	int h;
	int i;
	int j;

	h = ar[0][0];
	w = ar[0][1];
	i = 1;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			printf("%d  ", ar[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int **ft_to_array(td_list *list)
{
	td_list *tmp;
	int **ar;
	int i;
	int j;
	int a;
	int k;
	int len;
	char *line;

	tmp = list;
	k = ft_count_list(list) + 1;
	len = ft_width(list->line);
	ar = malloc(sizeof(int*) * k);
	ar[0] = (int*)malloc(sizeof(int) * 2);
	i = 1;
	while (i < k)
	{
		ar[i] = (int*)malloc(sizeof(int) * len);
		j = 0;
		a = 0;
		line = ft_strdup(tmp->line);
		while (line[j] != '\0')
		{
			if (line[j] != ' ' && (line[j - 1] == ' ' || j == 0))
			{
				ar[i][a] = ft_atoi(&line[j]);
				a++;
			}
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	ar[0][0] = k;
	ar[0][1] = len;
	return (ar);
}