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

int mouse_hook(int mouse, t_data *data)
{
    printf("mouse = %d \n", mouse);
    (void)data;
	if (mouse == 4)
		return (1);
			//zoom;
	if (mouse == 5)
		return (1);
		//dezoom;
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
	return (0);
}

int	quit(t_data *data)
{
	//ft_printf("%d\n", keycode);
	//(void)data;
	mlx_destroy_image(data->mlx, data->img1.img);
	mlx_destroy_image(data->mlx, data->img2.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	return (1);
}

void	loop(t_data *data)
{
		mlx_mouse_hook(data->mlx_win, &mouse_hook, data);
		mlx_key_hook(data->mlx_win, &key_hook, data);
		mlx_hook(data->mlx_win, 17, 1L << 0, quit, data); // mmarche pas
		mlx_loop(data->mlx);
}