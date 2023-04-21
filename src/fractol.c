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



int	ft_formule_mandelbrot(long double x, long double y, int max_iteration)
{
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
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
	}/*
	while ((z_r * z_r * z_r) + (z_i * z_i * z_i) < 4 && i < max_iteration)
	{
		tmp = z_r;
		z_r = z_r*z_r*z_r - 3*z_r*z_i*z_i + c_r;
		z_i = 3*tmp*tmp*z_i - z_i*z_i*z_i + c_i;
		i++;
	}*/
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
