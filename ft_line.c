#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int i;
	double dx;
	double dy;
	double step;
	double xinc;
	double yinc;
	double x;
	double y;

	x = (double)x1;
	y = (double)y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / (double)step;
	yinc = dy / (double)step;
	i = 0;
	while (i < step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, round(x), round(y), 0x0FFFFFF);
		x += xinc;
		y += yinc;
		i++;
	}
}