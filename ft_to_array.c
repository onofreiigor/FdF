/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:20:27 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:21:19 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		**ft_create_array(t_list_line *list)
{
	int			**ar;
	int			i;
	int			k;
	int			len;

	k = ft_count_list(list) + 1;
	len = ft_width(list->line);
	ar = malloc(sizeof(int*) * k);
	ar[0] = (int*)malloc(sizeof(int) * 2);
	i = 1;
	while (i < k)
	{
		ar[i] = (int*)malloc(sizeof(int) * len);
		i++;
	}
	ar[0][0] = k;
	ar[0][1] = len;
	return (ar);
}

int		**ft_to_array(t_list_line *list)
{
	int			**ar;
	int			i;
	int			j;
	int			a;

	ar = ft_create_array(list);
	i = 1;
	while (i < ar[0][0])
	{
		j = 0;
		a = 0;
		while (list->line[j] != '\0')
		{
			if (list->line[j] != ' ' && (list->line[j - 1] == ' ' || j == 0))
			{
				ar[i][a] = ft_atoi(&list->line[j]);
				a++;
			}
			j++;
		}
		list = list->next;
		i++;
	}
	return (ar);
}
