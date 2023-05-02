/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:46:37 by kscordel          #+#    #+#             */
/*   Updated: 2023/05/02 16:46:40 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

# include <X11/X.h>
# include <X11/keysym.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_point
{
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		ecart;
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

typedef struct s_data_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data_img;

typedef struct s_data
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
	char		fc;

}		t_data;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_color;

//Initialisation
void		init_data(t_data *data, char *name, char **option);
void		what_algo(t_data *data, char *name, char **option);

//Formule
int			ft_formule_mandelbrot(long double x, long double y, \
int max_iteration, t_math t);
int			ft_formule_mandelbrotn2(long double x, long double y, \
int max_iteration, t_math t);
int			ft_formule_mandelbrot3(long double x, long double y, \
int max_iteration, t_math t);
int			ft_julia(long double x, long double y, int max_iteration, t_math t);
int			ft_burning_ship(long double x, long double y, int max_iteration, \
t_math t);

//Affichage
void		createimg(t_data *data, int (*f)(long double x, long double y, \
int	max_iteration, t_math t));
void		stringput(t_data *data);

//Gestion graphique
int			key_hook(int key, t_data *data);
int			mouse_hook(int mouse, int x, int y, t_data *data);
void		redefinition(t_point *p, int x, int y, int E);
void		zoom(t_point *p, int E);

//Couleur
int			makecolor(int t, int red, int green, int blue);
void		my_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void		color_put(t_data *data, int iteration, int largeur, int hauteur);
void		ft_color_original(t_data *data, int iteration, int largeur, \
int hauteur);
void		original5(t_color *color, int *iteration);
void		original6(t_color *color, int *iteration);

//End
void		ft_clear_data(t_data *data);
void		bad_arg(t_data *data, bool b);
int			quit(t_data *data);

long double	ft_atolf(char *str);
long double	ft_abs(long double n);

#endif
