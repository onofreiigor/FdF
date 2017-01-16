#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

int	ft_isometric(int x)
{
	const double al = 35.264 * RAD;
	const double bt = 45.0 * RAD;
	double mat = 0;

	mat = (cos(bt) * cos(al) * cos(bt) * cos(bt)) + (sin(al) * sin(bt) * -sin(al) * -sin(bt))
		- (cos(al) * sin(bt) * cos(al) * -sin(bt)) - (cos(bt) * -sin(al) * sin(al) * cos(bt));

	x = x * round(mat);
	return (x);
}