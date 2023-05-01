/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:29:06 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/21 14:29:08 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	color_put(t_data *data, int iteration, int largeur, int hauteur)
{	
	if (data->fc == 0)
	{
		ft_color_original(data, iteration, largeur, hauteur);
		return ;
	}
	if (iteration == data->max_iteration)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, 0xFF000000);
	else if (data->fc == 1)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(255, (2 * iteration) % 256 + 50, (iteration) % 512 / 10, (iteration) % 256 /3));
	else if (data->fc == 2)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(255, (iteration % 512) / 2, (2* iteration % 512) + 50, (iteration % 512) / 4));
	else if (data->fc == 3)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(255, (iteration % 512) / 2, (iteration % 512), (iteration) % 256 + 40));

}

int	makecolor(int t, int red, int green, int blue)
{
	if (red > 255)
		red = 255;
	if ( green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}
