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
	//if (data->fc = 0)
		ft_color_original(data, iteration, largeur, hauteur);
	/*else if (data->fc = 1)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(255, (3* iteration) % 256, (1 * iteration) % 256, (10 * iteration) % 256));
	else if (data->fc == 2)

	else if (data->fc == 3)*/

	
}

void	original1(t_color *color, int *iteration)
{
	if (*iteration >= 64)
		{
			color->b += 128;
			color->g += 128;
		}
		else
		{
			color->b += (*iteration * 2);
			color->g += (*iteration * 2);
		}
		*iteration = *iteration - 50;
		if (*iteration > 0 && *iteration > 51)
			color->g += 102;
		else if (*iteration > 0)
			color->g += *iteration * 2;
		*iteration = *iteration - 51;
		if (*iteration > 0 && *iteration > 51)
			color->r -= 102;
		else if (*iteration > 0)
			color->r -= (*iteration * 2);
		*iteration = *iteration -51;
}

void	ft_color_original(t_data *data, int iteration, int largeur, int hauteur)
{
	t_color color;

	if (iteration == data->max_iteration)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, 0xFF000000);
	else if (iteration == 0)
		my_mlx_pixel_put(&data->img1, largeur, hauteur, 0xFFFF1919);
	else
	{	
		while (iteration > 0)
		{
		color.t = 255;
		color.b = 25;
		color.g = 25;
		color.r = 255;
		/*if (iteration >= 64)
		{
			color.b += 128;
			color.g += 128;
		}
		else
		{
			color.b += (iteration * 2);
			color.g += (iteration * 2);
		}
		iteration -= 50;
		if (iteration > 0 && iteration > 51)
			color.g += 102;
		else if (iteration > 0)
			color.g += iteration * 2;
		iteration -= 51;
		if (iteration > 0 && iteration > 51)
			color.r -= 102;
		else if (iteration > 0)
			color.r -= (iteration * 2);
		iteration -= 51;*/
		original1(&color, &iteration);
		if (iteration > 0 && iteration > 51)
		{
			color.r -= 102;
			color.b -= 102;
		}
		else if (iteration > 0)
		{
			color.r -= (iteration * 2);
			color.b -= (iteration * 2);
		}
		iteration -= 51;
		if (iteration > 0 && iteration > 51)
		{
			color.r -= 51;
			color.g -= 51;
			color.b += 51;
		}
		else if (iteration > 0)
		{
			color.r -= iteration;
			color.g -= iteration;
			color.b += iteration;
		}
		iteration -= 51;
		if (iteration > 0 && iteration > 51)
			color.b += 102;
		else if (iteration > 0)
			color.b += (iteration * 2);
		iteration -= 51;
		if (iteration > 0 && iteration > 51)
			color.g -= 102;
		else if (iteration > 0)
			color.g -= (iteration * 2);
		iteration -= 51;
		if (iteration > 0 && iteration >= 26)
			color.b += 51;
		else if (iteration > 0)
			color.b += (iteration * 2);
		iteration -= 26;
		if (iteration > 0 && iteration >= 26)
		{
			color.r += 51;
			color.g += 51;
		}
		else if (iteration > 0)
		{
			color.r += (iteration * 2);
			color.g += (iteration * 2);
		}
		iteration -= 26;
		if (iteration > 0 && iteration >= 26)
		{
			color.r += 51;
			color.g -= 51;
		}
	 	else if (iteration > 0)
		{
			color.r += (iteration * 2);
			color.g -= (iteration * 2);
		}
		iteration -= 26;
		if (iteration > 0 && iteration >= 51)
		{
			color.r += 102;
			color.g += 51;
		}
		else if (iteration > 0)
		{
			color.r += (iteration * 2);
			color.g += iteration;
		}
		iteration -= 51;
		if (iteration > 0 && iteration >= 26)
		{
			color.r += 51;
			color.g -= 51;
		}
		else if (iteration > 0)
		{
			color.r += (iteration * 2);
			color.g -= (iteration * 2);
		}
		iteration -= 26;
		if (iteration > 0 && iteration >= 51)
		{
			color.b -= 102;
			color.g -= 102;
		}
		else if (iteration > 0)
		{
			color.b -= (iteration * 2);
			color.g -= (iteration * 2);
		}
		iteration -= 51;
		
		if (iteration > 0 && iteration >= 64)
			color.b -= 127;
		else if (iteration > 0)
			color.b -= (iteration * 2);
		iteration -= 64;
		if (iteration > 0 && iteration >= 25)
		{
			color.b += 25;
			color.g += 25;
		}
		else if (iteration > 0)
		{
			color.b += iteration;
			color.g += iteration;
		}
		iteration -= 25;
		}
		my_mlx_pixel_put(&data->img1, largeur, hauteur, makecolor(color.t, color.r, color.g, color.b));
	
	}
}

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
