#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_line(void *mlx_ptr, void *win_ptr, t_seg *seg)
{
	int i;
	double dx;
	double dy;
	double step;
	double xinc;
	double yinc;
	double x;
	double y;

	x = (double)seg->x1;
	y = (double)seg->y1;
	dx = seg->x2 - seg->x1;
	dy = seg->y2 - seg->y1;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / (double)step;
	yinc = dy / (double)step;
	i = 0;
	while (i < step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, round(x), round(y), 0xFFFFFF);
		x += xinc;
		y += yinc;
		i++;
	}
}