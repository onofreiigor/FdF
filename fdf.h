#ifndef __FDF_H
# define __FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#define RAD M_PI / 180
#define AL RAD * 45 //rotate x;
#define BT RAD * 25	//roate y;
#define GM RAD * 35 // rotate z;
#define KEY_MAC 53
#define KEY_LINUX 65307

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

int ft_count_list(td_list *list);
void	ft_print_list(td_list *list);
td_list *ft_new_list(char *line);
void	ft_add_list(td_list *list, char *line);
td_list *ft_to_list(int fd);
void	ft_print_arr(int **ar);
int **ft_to_array(td_list *list);
t_seg *ft_new_seg(int x1, int y1, int z1, int x2, int y2, int z2);
void	ft_add_seg(t_seg *seg, int x1, int y1, int z1, int x2, int y2, int z2);
t_seg	*ft_to_seg(int **ar);
void	ft_print_seg(void *mlx_ptr, void *win_ptr, t_seg *seg);
t_seg	*ft_incr_map(t_seg *seg);
t_seg *ft_rotate_xy(t_seg *seg);
t_seg *ft_rotate_z(t_seg *seg);
void	ft_draw(td_list *list, void *mlx_ptr, void *win_ptr);
int ft_width(char *line);
void	ft_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
int	ft_isometric(int x);


#endif

/* Matrix rotation

in jur la x schimbam doar y:

y = y *cos(al) + z * sin(aL);

in jur la y schimbam doar x:

x = x *cos(al) + z * sin(aL);

in jur la z schimbam x si y

x = x * cos(al) - y * sin(al);
y = x * sin(al) + y * cos(al);

*/
