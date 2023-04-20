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
	if (data->img2.img)
		mlx_destroy_image(data->mlx, data->img2.img);
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


void	init_data(t_data *data, char *name)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(0);
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	if (data->width > data->height)
		data->width = data->height;
	else
		data->height = data->width;
	data->height -= 65;
	data->width -= 65;
	data->height = data->height / 100 * 100;
	data->width = data->width / 100 * 100;
	data->img1.img = mlx_new_image(data->mlx, data->width, data->height);
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, name);
	if (data->mlx_win == NULL)
		ft_clear_data(data);
	if (!data->img1.img)
	ft_clear_data(data);
	data->img1.addr = mlx_get_data_addr(data->img1.img, &data->img1.bits_per_pixel, &data->img1.line_length, &data->img1.endian);
	data->img2.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img2.img)
		ft_clear_data(data);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bits_per_pixel, &data->img2.line_length, &data->img2.endian);
	make_point(&data->p, data->width);
	data->max_iteration = 50;
}
