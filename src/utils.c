/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:19 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/10 15:01:54 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"



void	ft_clear_data(t_data *data)
{
	if (data->img1.img)
		mlx_destroy_image(data->mlx, data->img1.img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

void	make_point(t_point *p, int l)
{
	p->x1 = -2;
	p->x2 = 2;
	p->y1 = -2;
	p->y2 = 2;
	p->ecart = 4;
	p->zoom = l / p->ecart;
}

void	what_algo(t_data *data, char *name, char *option, char *option2)
{
	if (!ft_strncmp(name, "Mandelbrot", 11) && option == NULL)
		data->f = &ft_formule_mandelbrot;
	else if (!ft_strncmp(name, "Mandelbrot", 11) && option != NULL)
	{
		if (!ft_strncmp(option, "2", 2))
			data->f = &ft_formule_mandelbrot;
		else if (!ft_strncmp(option, "3", 2))
			data->f = &ft_formule_mandelbrot3;
		else if (!ft_strncmp(option, "4", 2))
			data->f = &ft_formule_mandelbrot4;
		else if (!ft_strncmp(option, "-2", 3))
			data->f = &ft_formule_mandelbrotn2;
	}
	else if (!ft_strncmp(name, "Julia", 6))
	{
		data->f = &ft_julia;
		if (option && option2)
		{
			data->mt.c_r = ft_atolf(option);
			data->mt.c_i = ft_atolf(option2);
		}
		else
		{
			data->mt.c_r = 1;
			data->mt.c_i = 1;
		}

	}
	else if (ft_strncmp(name, "Mandelbrot", 11) && ft_strncmp(name, "Julia", 6))
		ft_clear_data(data);
}

void	define_size(t_data *data)
{
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	if (data->width > data->height)
		data->width = data->height;
	else
		data->height = data->width;
	data->height -= 65;
	data->width -= 65;
	data->height = data->height / 100 * 100;
	data->width = data->width / 100 * 100;
}

void	init_data(t_data *data, char *name, char *option, char *option2)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(0);
	define_size(data);
	what_algo(data, name, option, option2);

	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, name);
	if (data->mlx_win == NULL)
		ft_clear_data(data);

	data->img1.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img1.img)
	ft_clear_data(data);
	data->img1.addr = mlx_get_data_addr(data->img1.img, &data->img1.bits_per_pixel, &data->img1.line_length, &data->img1.endian);
	
	make_point(&data->p, data->width);
	data->max_iteration = 50;
}
