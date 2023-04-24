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

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct	s_point
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	ecart;
	unsigned long	zoom;
}		t_point;


typedef struct s_math
{
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
}		t_math;

typedef struct	s_data_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data_img;


typedef struct  s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*f;
	t_data_img	img1;
	t_point		p;
	t_math		mt;
	int			width;
	int			height;
	int			max_iteration;
	bool		b;

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
void	color_put(t_data *data, int iteration, int largeur, int hauteur);

void	init_data(t_data *data, char *name, char *option, char *option2);
void	ft_clear_data(t_data *data);
int		quit(t_data *data);

int		key_hook(int key, t_data *data);
int		mouse_hook(int mouse, int x, int y, t_data *data);
void	loop(t_data *data);

void	mandelbrot(t_data *data);
void	createimg(t_data *data, int (*f)(long double x, long double y, int max_iteration));
void	createimg2(t_data *data, int (*f)(long double x, long double y, int max_iteration, t_math t));

int	ft_formule_mandelbrot(long double x, long double y, int max_iteration);
int	ft_formule_mandelbrot3(long double x, long double y, int max_iteration);
int	ft_formule_mandelbrot4(long double x, long double y, int max_iteration);
int	ft_formule_mandelbrotn2(long double x, long double y, int max_iteration);
int	ft_julia(long double x, long double y, int max_iteration, t_math t);
int	ft_burning_ship(long double x, long double y, int max_iteration);

void	stringput(t_data *data);
long double	ft_atolf(char *str);


#endif
