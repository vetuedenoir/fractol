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

long double	ft_abs(long double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	createimg(t_data *data, int (*f)(long double x, long double y,
int max_iteration, t_math t))
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
			color = f((double)largeur / (double)data->p.zoom + data->p.x1,
					(double)hauteur / (double)data->p.zoom - data->p.y2,
					data->max_iteration, data->mt);
			color_put(data, color, largeur, hauteur);
			largeur++;
		}
		hauteur++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1.img, 0, 0);
	if (data->b == 0)
		stringput(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 1 || argc > 5)
		bad_arg(&data, 1);
	init_data(&data, argv[1], &argv[2]);
	createimg(&data, data.f);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, quit, &data);
	mlx_loop(data.mlx);
	return (1);
}
