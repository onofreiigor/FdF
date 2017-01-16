/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:15:17 by ionofrei          #+#    #+#             */
/*   Updated: 2016/12/03 14:22:46 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

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

int ft_width(char *line)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (line[i - 1] == ' ' || i == 0))
			k++;
		i++;
	}
	return (k);
}

t_seg *ft_draw_square()
{
	t_seg *square;

	square = ft_new_seg(0, 0, 0, 50, 0, 0);
	ft_add_seg(square, 50, 0, 0, 50, 50 ,0);
	ft_add_seg(square, 0, 0, 0, 0, 50 ,0);
	ft_add_seg(square, 0, 50, 0, 50, 50, 0);

	return (square);
}

int	main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	int fd;
	t_seg *segment;
	//double t = 4.5;

	if (ac != 2)
		ft_error("NO file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Open");

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 500, "Hello MLX");

	segment = ft_to_seg(ft_to_array(ft_to_list(fd)));
	segment = ft_incr_map(segment);
	segment = ft_rotate_z(segment);
	segment = ft_rotate_xy(segment);
	
	ft_print_seg(mlx_ptr, win_ptr, segment);

	// segment = ft_draw_square();
	// segment = ft_incr_map(segment);
	// segment = ft_rotate_map(segment);
	// ft_print_seg(mlx_ptr, win_ptr, segment);

	mlx_key_hook(win_ptr, ft_printf_key, 0);
	mlx_mouse_hook(win_ptr, ft_mouse, 0);
	mlx_loop(mlx_ptr);
	close(fd);
	return (0);
}
