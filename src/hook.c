/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:11:53 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/17 19:11:58 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mouse2(int mouse, t_data *data)
{
	unsigned long	s;

	if (mouse == 4)
	{
		s = data->p.zoom * 0.05;
		if (ULLONG_MAX - s > data->p.zoom)
			data->p.zoom = data->p.zoom * 1.05;
		else
			data->p.zoom = ULLONG_MAX;
	}
	if (mouse == 5)
	{	
		if (data->p.zoom == 2 || data->p.zoom == 1)
			data->p.zoom = 1;
		else
			data->p.zoom = data->p.zoom * 0.95;
	}
}

int	mouse_hook(int mouse, int x, int y, t_data *data)
{
	if (mouse != 4 && mouse != 5 && mouse != 1 && mouse != 3)
		return (1);
	redefinition(&data->p, x, y, data->height);
	mouse2(mouse, data);
	if (mouse == 1)
	{
		if (data->p.zoom < ULLONG_MAX / 2)
			data->p.zoom = data->p.zoom * 2.0;
		else
			data->p.zoom = ULLONG_MAX;
	}
	if (mouse == 3)
	{
		if (data->p.zoom == 2 || data->p.zoom == 1)
			data->p.zoom = 1;
		else
			data->p.zoom = data->p.zoom * 0.5;
	}
	zoom(&data->p, data->height);
	createimg(data, data->f);
	return (0);
}

int	key2(int key, t_data *data)
{
	static int	coef = 1;

	if (key == 65450)
	{
		coef *= 10;
		return (1);
	}
	if (key == 65455)
	{
		if (coef >= 10)
			coef /= 10;
		return (1);
	}
	if (key == 65451)
		data->max_iteration = data->max_iteration + coef;
	if (key == 65453)
	{
		if (data->max_iteration - coef <= 0)
			data->max_iteration = 1;
		else
			data->max_iteration = data->max_iteration - coef;
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 65307)
		quit(data);
	if (key == 115)
	{
		if (data->b == 0)
			data->b = 1;
		else
			data->b = 0;
	}
	if (key2(key, data))
		return (1);
	if (key == 65361)
		redefinition(&data->p, data->width / 4, data->height / 2, \
		data->height);
	if (key == 65363)
		redefinition(&data->p, (data->width / 4) * 3, data->height / 2, \
		data->height);
	if (key == 65362)
		redefinition(&data->p, data->width / 2, data->height / 4, \
		data->height);
	if (key == 65364)
		redefinition(&data->p, data->width / 2, (data->height / 4) * 3, \
		data->height);
	createimg(data, data->f);
	return (1);
}

int	quit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img1.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
