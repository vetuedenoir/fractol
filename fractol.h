/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:46:37 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/10 17:32:40 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH			1600
# define HEIGHT			1000
# define MAX_ITERATION	50

typedef struct	s_point
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
}		t_point;


typedef struct	s_data_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_data_img;


typedef struct  s_data
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	img1;
	t_data_img	img2;
	int			width;
	int			height;
}       	t_data;

typedef struct  s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}       	t_color;

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color);
int		makecolor(int t, int rouge, int green, int blue);
void	init_data(t_data *data);
void	ft_clear_data(t_data *data);
int		quit(t_data *data);
int		key_hook(int key, t_data *data);
int		mouse_hook(int mouse, t_data *data);
void	loop(t_data *data);

#endif
