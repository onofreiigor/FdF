/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:21:37 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:24:18 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

int		*ft_calc_margin(t_seg *seg)
{
	int		*ar;
	t_seg	*tmp;
	int		x_start;
	int		y_start;

	ar = (int*)malloc(sizeof(int) * 2);
	tmp = seg;
	x_start = tmp->x1;
	y_start = tmp->y1;
	tmp = tmp->next;
	ar[0] = x_start;
	ar[1] = y_start;
	while (tmp != NULL)
	{
		if (tmp->x1 < ar[0])
			ar[0] = tmp->x1;
		if (tmp->y1 < ar[0])
			ar[0] = tmp->y1;
		if (tmp->x2 < ar[0])
			ar[0] = tmp->x2;
		if (tmp->y2 < ar[0])
			ar[0] = tmp->y2;
		tmp = tmp->next;
	}
	ar[0] = x_start - ar[0];
	ar[1] = y_start - ar[1];
	return (ar);
}

int		*ft_calc_window_size(t_seg *seg)
{
	int		*ar;
	t_seg	*tmp;

	ar = (int*)malloc(sizeof(int) * 2);
	ar[0] = 0;
	ar[1] = 0;
	tmp = seg;
	while (tmp != NULL)
	{
		if (tmp->x1 > ar[0])
			ar[0] = tmp->x1;
		if (tmp->y1 > ar[1])
			ar[1] = tmp->y1;
		if (tmp->x2 > ar[0])
			ar[0] = tmp->x1;
		if (tmp->y2 > ar[1])
			ar[1] = tmp->y2;
		tmp = tmp->next;
	}
	if (ar[0] > W_MAX)
		ar[0] = W_MAX;
	if (ar[1] > H_MAX)
		ar[1] = H_MAX;
	return (ar);
}

t_seg	*ft_incr_map(t_seg *seg)
{
	t_seg	*tmp;
	int		size;

	size = 35;
	tmp = seg;
	while (tmp != NULL)
	{
		tmp->x1 *= size;
		tmp->x2 *= size;
		tmp->y1 *= size;
		tmp->y2 *= size;
		tmp->z1 *= 3;
		tmp->z2 *= 3;
		tmp = tmp->next;
	}
	return (seg);
}

t_seg	*ft_rotate_xy(t_seg *seg)
{
	t_seg	*tmp;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	tmp = seg;
	while (tmp != NULL)
	{
		x1 = tmp->x1;
		y1 = tmp->y1;
		x2 = tmp->x2;
		y2 = tmp->y2;
		y1 = round(tmp->y1 * cos(AL) - tmp->z1 * sin(AL));
		x1 = round(tmp->x1 * cos(BT) - tmp->z1 * sin(BT));
		y2 = round(tmp->y2 * cos(AL) - tmp->z2 * sin(AL));
		x2 = round(tmp->x2 * cos(BT) - tmp->z2 * sin(BT));
		tmp->x1 = x1;
		tmp->y1 = y1;
		tmp->x2 = x2;
		tmp->y2 = y2;
		tmp = tmp->next;
	}
	return (seg);
}

t_seg	*ft_rotate_z(t_seg *seg)
{
	t_seg	*tmp;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	tmp = seg;
	while (tmp != NULL)
	{
		x1 = tmp->x1;
		y1 = tmp->y1;
		x2 = tmp->x2;
		y2 = tmp->y2;
		y1 = round(tmp->y1 * cos(GM) + tmp->x1 * sin(GM));
		x1 = round(tmp->x1 * cos(GM) - tmp->y1 * sin(GM));
		y2 = round(tmp->y2 * cos(GM) + tmp->x2 * sin(GM));
		x2 = round(tmp->x2 * cos(GM) - tmp->y2 * sin(GM));
		tmp->x1 = x1;
		tmp->y1 = y1;
		tmp->x2 = x2;
		tmp->y2 = y2;
		tmp = tmp->next;
	}
	return (seg);
}
