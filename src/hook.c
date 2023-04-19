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

void	zoom(t_point *p, int E)
{
	double	dif;

	dif = (p->ecart - ((double)E / (double)p->zoom)) / (double)2;
	if (p->x1 > 0)
		p->x1 = p->x1 - dif;
	else
		p->x1 = p->x1 + dif;
	if (p->x2 > 0)
		p->x2 = p->x2 - dif;
	else
		p->x2 = p->x2 + dif;
	if (p->y1 > 0)
		p->y1 = p->y1 - dif;
	else
		p->y1 = p->y1 - dif;
	if (p->y2 > 0)
		p->y2 = p->y2 - dif;
	else
		p->y2 = p->y2 - dif;
	p->ecart = (double)E / (double)p->zoom; 
}


void	redefinition(t_point *p, int x, int y, int E)
{
	int	m;
	int	r;

	m = E / 2;
	r = x - m;
	p->x1 = p->x1 + ((double)r / (double)p->zoom);
	p->x2 = p->x2 + ((double)r / (double)p->zoom);
	r = (y - m) * -1;
	p->y1 = p->y1 + ((double)r / (double)p->zoom);
	p->y2 = p->y2 + ((double)r / (double)p->zoom);
//	printf("x1 = %f x2 = %f et y1 = %f , y2 = %f\n", p->x1, p->x2, p->y1, p->y2);
}

int mouse_hook(int mouse, int x, int y, t_data *data)
{
	(void)data;
	printf("mouse = %d\n", mouse);
	printf("souris coordonne :\n\t x = %d et y = %d\n", x, y);
	if (mouse != 4 && mouse != 5 && mouse != 1 && mouse != 3)
		return (1);
	redefinition(&data->p, x, y , data->height);
	if (mouse == 4)
		data->p.zoom = data->p.zoom * 1.05;
	if (mouse == 5)
		data->p.zoom = data->p.zoom * 0.95;
	if (mouse == 1)
		data->p.zoom = data->p.zoom * 2.0;
	if (mouse == 3)
		data->p.zoom = data->p.zoom * 0.5;
	zoom(&data->p, data->height);
	mandelbrot(data);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == 65307 || key == 99)
	{
		mlx_destroy_image(data->mlx, data->img1.img);
		mlx_destroy_image(data->mlx, data->img2.img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	if (key == 65451)
		data->max_iteration = data->max_iteration + 10;
	if (key == 65453)
		data->max_iteration = data->max_iteration - 1;
	if (key == 65361) // gauche
		redefinition(&data->p, data->width / 4, data->height / 2 , data->height);
	if (key == 65363) // droite
		redefinition(&data->p, (data->width / 4) * 3, data->height / 2 , data->height);
	if (key == 65362) // haut
		redefinition(&data->p, data->width / 2, data->height / 4 , data->height);
	if (key == 65364) // bas
		redefinition(&data->p, data->width / 2, (data->height / 4) * 3, data->height);
	mandelbrot(data);
	return (1);
}

int	quit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img1.img);
	mlx_destroy_image(data->mlx, data->img2.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

void	loop(t_data *data)
{
		mlx_mouse_hook(data->mlx_win, mouse_hook, data);
		mlx_key_hook(data->mlx_win, &key_hook, data);
		mlx_hook(data->mlx_win, 17, 1L << 0, quit, data);
		mlx_loop(data->mlx);
}
