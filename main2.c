/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:15:17 by ionofrei          #+#    #+#             */
/*   Updated: 2016/12/25 11:46:52 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_print_list(t_coord *list);

void	ft_error(char *er)
{
	printf("%s error\n", er);
	exit (1);
}

int	ft_printf_key(int keykode, void *param)
{
	//printf("key kode %d\n", keykode);
	if (keykode == 53)
		exit (1);

	param++;
	param--;
	return (0);
}

int ft_mouse(int key, int x, int y, void *param)
{
	//printf("mouse key: %d x = %d y = %d\n", key, x, y);
	if (key == 53 && x == 0 && y == 0)
		exit (1);
	param++;
	param--;
	return (0);
}

int ft_count(int fd)
{
	int s;
	char *line;

	line = NULL;
	s = 0;
	while (get_next_line(fd, &line) > 0)
		s++;
	return (s);
}

int ft_rotate_x(int x, int y)
{
	x = x * cos(RAD * AL) - y * sin(RAD * AL);
	return (x);
}

int ft_rotate_y(int x, int y)
{
	y = x * sin(RAD * AL) + y * cos(RAD * AL);
	return (y);
}

void	ft_draw(fdf_list *list, void *mlx_ptr, void *win_ptr)
{
	fdf_list *tmp;
	char *l1 = NULL;
	char *l2 = NULL;
	int  a = 20;
	int i = 0;
	int j = a;
	int k = 0;
	int x1 = a;
	int y1 = a;
	int x2 = a;
	int y2 = a;
	int x3 = a;
	int y3 = a;

	tmp = list;
	l2 = ft_strdup(tmp->l);
	while (tmp != NULL)
	{
		l1 = ft_strdup(l2);
		l2 = ft_strdup(tmp->l);
		while (l2[i] != '\0')
		{
			if (l2[i] != ' ' && (l2[i - 1] == ' ' || i == 0))
			{
				x1 = x2;
				x2 = a + k;
				y1 = y2;
				y2 = j;
				ft_line(mlx_ptr, win_ptr, x1, y1, x2, y2);
				if (tmp->next != NULL)
				{
					x3 = x1;
					y3 = j + 1 + a;
					ft_line(mlx_ptr, win_ptr, x1, y1, x3, y3);					
				}
				k += 1 + a;
			}
			i++;
		}
		tmp = tmp->next;
		i = 0;
		k = 0;
		j += 1 + a;
	}
}

t_coord *ft_new_list(int x, int y, int z)
{
	t_coord *new;

	new = (t_coord*)malloc(sizeof(t_coord));
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

void	ft_add_list(t_coord *list, int x, int y, int z)
{
	t_coord *tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_list(x, y, z);
}

void	ft_print_list(t_coord *list)
{
	t_coord *tmp;

	tmp = list;
	printf("Start List:\n");
	while (tmp != NULL)
	{
		printf("x: %d y: %d z: %d\n", tmp->x, tmp->y, tmp->z);
		tmp = tmp->next;
	}
}

t_seg *ft_new_lst_seg(t_coord *p1, t_coord *p2)
{
	t_seg *new;

	new = (t_seg*)malloc(sizeof(t_seg));
	new->x1 = p1->x;
	new->y1 = p1->y;
	new->z1 = p1->z;
	new->x2 = p2->x;
	new->y2 = p2->y;
	new->z2 = p2->z;
	new->next = NULL;
	return (new);
}

void	ft_add_lst_seg(t_seg *seg, t_coord *p1, t_coord *p2)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_lst_seg(p1, p2);
}

void	ft_print_seg(void *mlx_ptr, void *win_ptr, t_seg *seg)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp != NULL)
	{
		//printf("x1: %d y1: %d x2: %d y2: %d\n", tmp->x1, tmp->y1, tmp->x2, tmp->y2);
		ft_line(mlx_ptr, win_ptr, tmp->x1, tmp->y1, tmp->x2, tmp->y2);
		tmp = tmp->next;
	}
}

t_coord *ft_coord_iter(t_coord *point, int width)
{
	t_coord *tmp;

	tmp = point;
	while (width> 0)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
		width--;
	}
	if (width == 0)
		return (tmp);
	else
		return (point);
}

t_seg	*ft_to_seg(t_coord *list)
{
	t_seg *seg;
	t_coord *tmp;
	int f;
	int width;
	int height;

	f = 0;
	width = list->x;
	height = list->y;
	tmp = list->next;
	while (tmp->next != NULL)
	{
		if (f == 0)
		{
			f = 1;
			seg = ft_new_lst_seg(tmp, tmp->next);
			ft_add_lst_seg(seg, tmp, ft_coord_iter(tmp, width));
		}
		else
		{
			ft_add_lst_seg(seg, tmp, tmp->next);
			ft_add_lst_seg(seg, tmp, ft_coord_iter(tmp, width));
			//printf("x: %d, y: %d, z: %d\n", tmp->x, tmp->y, tmp->z);
		}
		tmp = tmp->next;
	}
	//printf("x1: %d y1: %d x2: %d y2: %d\n", seg->x1, seg->y1, seg->x2, seg->y2);
	return (seg);
}

t_coord	*ft_to_list(int fd)
{
	t_coord *list;
	t_coord *tmp;
	int i;
	int j;
	int k;
	char *line;

	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		k = 0;
		while (line[i] != '\0')
		{
			if (line[i] != ' ' && (line[i - 1] == ' ' || i == 0))
			{
				if (i == 0 && j == 0)
					list = ft_new_list(i, j, ft_atoi(&line[i]));
				else
				{
					k++;
					ft_add_list(list, i, j, ft_atoi(&line[i]));
				}
			}
			i++;
		}
		j += 10;
	}
	tmp = ft_new_list(k, j, 0);
	tmp->next = list;
	return (tmp);
}

int	main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	int fd;
	//double t = 4.5;

	if (ac != 2)
		ft_error("NO file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Open");

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello MLX");

	//ft_draw(ft_to_list(fd), mlx_ptr, win_ptr);
	//printf("double: %f int: %d round: %f int_round: %d\n", t, (int)t, round(t), (int)round(t));
	//ft_line(mlx_ptr, win_ptr, 10, 10, 300, 200);

	//printf("%d\n", ft_isometric(10));	
	//printf("cos45: %f sqrt: %f", cos(45 * RAD), sqrt(3) / sqrt(6));


	//ft_print_list(ft_to_list(fd));
	ft_print_seg(mlx_ptr, win_ptr, ft_to_seg(ft_to_list(fd)));

	mlx_key_hook(win_ptr, ft_printf_key, 0);
	mlx_mouse_hook(win_ptr, ft_mouse, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
