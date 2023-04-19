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

#include "../fractol.h"

void	color_put(t_data *data, int iteration, int largeur, int hauteur)
{
	t_color color;
	color.b = 0;
	color.g = 0;
	color.r = 128;
	if (iteration == data->max_iteration)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, 0xFF000000);
	else
	{
		color.t = 256;
		iteration++;
		while (color.r < 256 && --iteration)
		{
			color.r = color.r + 2;
			color.b = color.b + 1;
		}
		while (color.g < 256 && --iteration)
		{
			color.g = color.g + 2;
			color.r = color.r - 2;
		}
		while (color.b < 256 && --iteration)
		{
			color.b = color.b + 2;
			color.r = color.r + 2;
		}
		while (color.b > 100)
		{
			color.b--;
			color.r--;
			color.g--;
		}
		while (color.b > 0)
		{
			color.b -= 2;
		}
		while (color.r > 0)
		{
			color.r -= 2;
		}
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(color.t, color.r, color.g, color.b));
	}
}

int	ft_formule_mandelbrot(double x, double y, int max_iteration)
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
	//printf("cr = %lf et c_i = %lf \n", c_r, c_i);
	while (z_r * z_r + z_i * z_i < 4 && i < max_iteration)
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
	int		largeur;
	int		hauteur;
	int		color;

	
	hauteur = 0;
	while (hauteur < data->height)
	{
		largeur = 0;
		while (largeur < data->width)
		{
			color = ft_formule_mandelbrot((double)largeur / (double)data->p.zoom + data->p.x1, (double)hauteur / (double)data->p.zoom - data->p.y2, data->max_iteration);
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
		init_data(&data, argv[1]);
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			mandelbrot(&data);
		else if (!ft_strncmp(argv[1], "Julia", 6))
		{
			//julia(&data);
			return (1);
		}
		loop(&data);
	}
	else
		return (1);
}
