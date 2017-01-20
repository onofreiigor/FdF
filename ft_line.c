/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:19:02 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:20:09 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_line(void *mlx_ptr, void *win_ptr, t_seg *seg)
{
	double	dx;
	double	dy;
	double	step;
	double	x;
	double	y;

	x = (double)seg->x1;
	y = (double)seg->y1;
	dx = seg->x2 - seg->x1;
	dy = seg->y2 - seg->y1;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / (double)step;
	dy = dy / (double)step;
	while (step > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, round(x), round(y), 0xFFFFFF);
		x += dx;
		y += dy;
		step--;
	}
}
