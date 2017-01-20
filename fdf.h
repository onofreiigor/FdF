/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:28:49 by ionofrei          #+#    #+#             */
/*   Updated: 2017/01/20 16:36:17 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define RAD M_PI / 180
# define AL RAD * 45
# define BT RAD * 25
# define GM RAD * 35
# define KEY_MAC 53
# define KEY_LINUX 65307
# define W_MAX 1920
# define H_MAX 1080

typedef struct		s_list_line
{
	char				*line;
	struct s_list_line	*next;
}					t_list_line;

typedef struct		s_point
{
	int x;
	int y;
	int z;
}					t_point;

typedef struct		s_seg
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	struct s_seg	*next;
}					t_seg;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}					t_coord;

int					ft_count_list(t_list_line *list);
void				ft_print_list(t_list_line *list);
t_list_line			*ft_new_list(char *line);
void				ft_add_list(t_list_line *list, char *line);
t_list_line			*ft_to_list(int fd);
void				ft_print_arr(int **ar);
int					**ft_to_array(t_list_line *list);
t_seg				*ft_new_seg(int x1, int y1, int z1, int x2, int y2, int z2);
void				ft_add_seg(t_seg *seg, int x1, int y1, int z1,
					int x2, int y2, int z2);
t_seg				*ft_to_seg(int **ar);
void				ft_print_seg(void *mlx_ptr, void *win_ptr, t_seg *seg);
t_seg				*ft_incr_map(t_seg *seg);
t_seg				*ft_margin_map(t_seg *seg, int m_x, int m_y);
t_seg				*ft_rotate_xy(t_seg *seg);
t_seg				*ft_rotate_z(t_seg *seg);
void				ft_draw(t_list_line *list, void *mlx_ptr, void *win_ptr);
int					ft_width(char *line);
void				ft_line(void *mlx_ptr, void *win_ptr, t_seg *seg);
int					ft_isometric(int x);
int					*ft_calc_window_size(t_seg *seg);
int					*ft_calc_margin(t_seg *seg);

#endif
