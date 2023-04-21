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


void	createimg(t_data *data, int (*f)(long double x, long double y, int max_iteration))
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
			color = f((double)largeur / (double)data->p.zoom + data->p.x1, (double)hauteur / (double)data->p.zoom - data->p.y2, data->max_iteration);
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
	if (!argv[1])
		return (1);
	init_data(&data, argv[1], argv[2]);
	createimg(&data, data.f);
	loop(&data);
}
