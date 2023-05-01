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

void	make_point(t_point *p, int l)
{
	p->x1 = -2;
	p->x2 = 2;
	p->y1 = -2;
	p->y2 = 2;
	p->ecart = 4;
	p->zoom = l / p->ecart;
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

void	init_data(t_data *data, char *name, char **option)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(0);
	define_size(data);
	if (ft_strncmp(name, "Mandelbrot", 11) && ft_strncmp(name, "Julia", 6) && ft_strncmp(name, "Burning_ship", 13))
		bad_arg(data, 1);
	what_algo(data, name, option);

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
