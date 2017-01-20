/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:15:17 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:13:05 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	ft_error(char *er)
{
	ft_putstr("ERROR: ");
	ft_putstr(er);
	ft_putstr("!\n");
	exit(1);
}

int		ft_printf_key(int keykode, void *param)
{
	if (keykode == KEY_MAC)
		exit(1);
	param++;
	param--;
	return (0);
}

int		ft_width(char *line)
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

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	int		*ar;
	t_seg	*segment;

	if (ac != 2)
		ft_error("NO file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Open file");
	segment = ft_to_seg(ft_to_array(ft_to_list(fd)));
	segment = ft_incr_map(segment);
	segment = ft_rotate_z(segment);
	segment = ft_rotate_xy(segment);
	mlx_ptr = mlx_init();
	ar = ft_calc_margin(segment);
	segment = ft_margin_map(segment, ar[0], ar[1]);
	ar = ft_calc_window_size(segment);
	win_ptr = mlx_new_window(mlx_ptr, ar[0], ar[1], "FDF");
	ft_print_seg(mlx_ptr, win_ptr, segment);
	mlx_key_hook(win_ptr, ft_printf_key, 0);
	mlx_loop(mlx_ptr);
	close(fd);
	return (0);
}
