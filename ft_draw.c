#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_draw(td_list *list, void *mlx_ptr, void *win_ptr)
{
	td_list *tmp;
	//char *l1 = NULL;
	char *l2 = NULL;
	int  a = 20;
	int i = 0;
	int j = a;
	int k = 0;
	int x1 = a;
	int y1 = a;
	int x2 = a;
	int y2 = a;
	int x3 = a;
	int y3 = a;

	tmp = list;
	l2 = ft_strdup(tmp->line);
	while (tmp != NULL)
	{
		//l1 = ft_strdup(l2);
		l2 = ft_strdup(tmp->line);
		while (l2[i] != '\0')
		{
			if (l2[i] != ' ' && (l2[i - 1] == ' ' || i == 0))
			{
				x1 = x2;
				x2 = a + k;
				y1 = y2;
				y2 = j;
				ft_line(mlx_ptr, win_ptr, x1, y1, x2, y2);
				if (tmp->next != NULL)
				{
					x3 = x1;
					y3 = j + 1 + a;
					ft_line(mlx_ptr, win_ptr, x1, y1, x3, y3);					
				}
				k += 1 + a;
			}
			i++;
		}
		tmp = tmp->next;
		i = 0;
		k = 0;
		j += 1 + a;
	}
}