/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_margin_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:24:33 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:25:14 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

t_seg	*ft_margin_map(t_seg *seg, int m_x, int m_y)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp != NULL)
	{
		tmp->x1 += m_x;
		tmp->x2 += m_x;
		tmp->y1 += m_y;
		tmp->y2 += m_y;
		tmp = tmp->next;
	}
	m_x = m_y;
	return (seg);
}
