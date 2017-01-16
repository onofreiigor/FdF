#ifndef __FDF_H
# define __FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#define RAD M_PI / 180
#define AL RAD * 35

typedef struct	fdf_list
{
	char *line;
	struct fdf_list *next;
}				td_list;

typedef struct f_point
{
	int x;
	int y;
	int z;
}			t_point;

typedef struct f_seg
{
	int x1;
	int y1;
	int z1;
	int x2;
	int y2;
	int z2;
	struct f_seg *next;
}				t_seg;

typedef struct f_coord
{
	int x;
	int y;
	int z;
	struct f_coord *next;
}			t_coord;

void	ft_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
int	ft_isometric(int x);

#endif

/* Matrix rotation

in jur la x schimbam doar y:

y = y *cos(al) + z * sin(aL);

in jur la y schimbam doar x:

x = x *cos(al) + z * sin(aL);

*/