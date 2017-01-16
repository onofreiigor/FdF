#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

t_seg	*ft_incr_map(t_seg *seg)
{
	t_seg *tmp;
	int size;
	int marginx;
	int marginy;

	marginx = 200;
	marginy = -100;
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
		tmp->x1 += marginx;
		tmp->x2 += marginx;
		tmp->y1 += marginy;
		tmp->y2 += marginy;
		tmp = tmp->next;
	}
	return (seg);
}

t_seg *ft_rotate_xy(t_seg *seg)
{
	t_seg *tmp;
	int x1;
	int y1;
	int x2;
	int y2;

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

t_seg *ft_rotate_z(t_seg *seg)
{
	t_seg *tmp;
	int x1;
	int y1;
	int x2;
	int y2;

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