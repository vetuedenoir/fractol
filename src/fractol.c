/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:46:40 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/10 18:12:26 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_put(t_data *data, int iteration, int largeur, int hauteur)
{
	t_color color;

	if (iteration == MAX_ITERATION)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, 0xFF000000);
	else
	{
		color.t = 256;
		color.r = 128 + iteration;
		color.g = 0;
		color.b = 0;
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(color.t, color.r, 0, 0));
	}

}

int	ft_formule_mandelbrot(double x, double y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	c_r = x;
	c_i = y;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITERATION)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	t_point	p;
	int		zoom;
	int		largeur;
	int		hauteur;
	int		color;


	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, "Mandelbrot");
	if (data->mlx_win == NULL)
		ft_clear_data(data);
	p.x1 = -2.2;
	p.x2 = 1.8;
	p.y1 = -2;
	p.y2 = 2;
	zoom = 200;
	hauteur = 0;
	while (hauteur < data->height)
	{
		largeur = 0;
		while (largeur < data->width)
		{
			color = ft_formule_mandelbrot(largeur / zoom + p.x1, hauteur / zoom + p.y1);
			//printf("color = %d	: x = %d et y = %d", color, largeur, hauteur);
			color_put(data, color, largeur, hauteur);
			largeur++;
		}
		hauteur++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1.img, 0, 0);
}


int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (argc == 1)
		return (1);
	if (!ft_strncmp(argv[1], "Mandelbrot", 11) || !ft_strncmp(argv[1], "Julia", 6))
	{
		data.mlx = mlx_init();
		if (!data.mlx)
			exit(0);
		init_data(&data);
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			mandelbrot(&data);
		else if (!ft_strncmp(argv[1], "Julia", 6))
		{
			//julia(&data);
			return (1);
		}
		mlx_hook(data.mlx_win, 33, 1L << 17, &quit, &data);
		mlx_loop(data.mlx);
	}
	else
		return (1);
}
