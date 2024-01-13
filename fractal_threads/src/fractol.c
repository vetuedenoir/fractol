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

void	*routine(void *arg)
{
	int	largeur;
	int	color;
	t_data *data;

	data = (t_data *)arg;
	int	(*f)(long double x, long double y, int max_iteration, \
t_math t) = data->f;
	largeur = 0;
	while (largeur < data->width)
	{
		color = f((double)largeur / (double)data->p.zoom + data->p.x1,
				(double)(data->hauteur) / (double)data->p.zoom - data->p.y2,
					data->max_iteration, data->mt);	
		color_put(data, color, largeur, (data->hauteur));
		largeur++;
	}
	return (arg);
}

void	createimg(t_data *data, pthread_t *th)
{
	int		hauteur;
	int		i;
	static t_data dt[NUM_THREADS];

	for (i = 0; i < NUM_THREADS; i++)
		dt[i] = *data;
	hauteur = 0;
	while (hauteur < data->height)
	{
		i = 0;
		while (hauteur + i < data->height && i < NUM_THREADS)
		{
			dt[i].hauteur = hauteur + i;
			pthread_create(&th[i], NULL, &routine, &dt[i]);
			i++;
		}
		while (--i >= 0)
			pthread_join(th[i], NULL);
		hauteur += NUM_THREADS;
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
	createimg(&data, data.th);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, quit, &data);
	mlx_loop(data.mlx);
	return (1);
}
