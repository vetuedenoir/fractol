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

int	makecolor(int t, int rouge, int green, int blue)
{
	return (t << 24 | rouge << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	ft_clear_data(t_data *data)
{
	if (data->img2.img)
	{
		mlx_destroy_image(data->mlx, data->img2.img);
		free(data->img2.img);
	}
	if (data->img1.img)
	{
		mlx_destroy_image(data->mlx, data->img1.img);
		free(data->img1.img);
	}
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->mlx_win);
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

void	init_data(t_data *data)
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
	data->img1.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img1.img)
		ft_clear_data(data);
	data->img1.addr = mlx_get_data_addr(data->img1.img, &data->img1.bits_per_pixel, &data->img1.line_length, &data->img1.endian);
	data->img2.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img2.img)
		ft_clear_data(data);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bits_per_pixel, &data->img2.line_length, &data->img2.endian);
}
