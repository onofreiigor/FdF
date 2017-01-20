/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:14:54 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:18:47 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

t_seg	*ft_new_seg(int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_seg *new;

	new = (t_seg*)malloc(sizeof(t_seg));
	new->x1 = x1;
	new->y1 = y1;
	new->z1 = z1;
	new->x2 = x2;
	new->y2 = y2;
	new->z2 = z2;
	new->next = NULL;
	return (new);
}

void	ft_add_seg(t_seg *seg, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_seg(x1, y1, z1, x2, y2, z2);
}

void	ft_print_seg(void *mlx_ptr, void *win_ptr, t_seg *seg)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp != NULL)
	{
		ft_line(mlx_ptr, win_ptr, tmp);
		tmp = tmp->next;
	}
}

t_seg	*ft_to_seg(int **ar)
{
	t_seg	*seg;
	int		i;
	int		j;

	i = 1;
	j = 0;
	seg = ft_new_seg(0, 0, 0, 0, 0, 0);
	while (i < ar[0][0])
	{
		while (j < ar[0][1])
		{
			if (i == ar[0][0] - 1)
				if (j != ar[0][1] - 1)
					ft_add_seg(seg, j, i - 1, ar[i][j],
							j + 1, i - 1, ar[i][j + 1]);
				else
					break ;
			else if (j == ar[0][1] - 1)
				ft_add_seg(seg, j, i - 1, ar[i][j], j, i, ar[i + 1][j]);
			else
			{
				ft_add_seg(seg, j, i - 1, ar[i][j], j + 1, i - 1, ar[i][j + 1]);
				ft_add_seg(seg, j, i - 1, ar[i][j], j, i, ar[i + 1][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (seg);
}
