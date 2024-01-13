/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:21:58 by kscordel          #+#    #+#             */
/*   Updated: 2023/05/02 16:28:57 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	original2(t_color *color, int *iteration)
{
	if (*iteration > 0 && *iteration > 51)
	{
		color->r -= 102;
		color->b -= 102;
	}
	else if (*iteration > 0)
	{
		color->r -= (*iteration * 2);
		color->b -= (*iteration * 2);
	}
	*iteration = *iteration - 51;
	if (*iteration > 0 && *iteration > 51)
	{
		color->r -= 51;
		color->g -= 51;
		color->b += 51;
	}
	else if (*iteration > 0)
	{
		color->r -= *iteration;
		color->g -= *iteration;
		color->b += *iteration;
	}
	*iteration = *iteration - 51;
}

void	original3(t_color *color, int *iteration)
{
	if (*iteration > 0 && *iteration > 51)
		color->b += 102;
	else if (*iteration > 0)
		color->b += (*iteration * 2);
	*iteration = *iteration - 51;
	if (*iteration > 0 && *iteration > 51)
		color->g -= 102;
	else if (*iteration > 0)
		color->g -= (*iteration * 2);
	*iteration = *iteration - 51;
	if (*iteration > 0 && *iteration >= 26)
		color->b += 51;
	else if (*iteration > 0)
		color->b += (*iteration * 2);
	*iteration = *iteration - 26;
	if (*iteration > 0 && *iteration >= 26)
	{	
		color->r += 51;
		color->g += 51;
	}
	else if (*iteration > 0)
	{
		color->r += (*iteration * 2);
		color->g += (*iteration * 2);
	}
}

void	original4(t_color *color, int *iteration)
{
	*iteration = *iteration - 26;
	if (*iteration > 0 && *iteration >= 26)
	{
		color->r += 51;
		color->g -= 51;
	}
	else if (*iteration > 0)
	{
		color->r += (*iteration * 2);
		color->g -= (*iteration * 2);
	}
	*iteration = *iteration - 26;
	if (*iteration > 0 && *iteration >= 51)
	{
		color->r += 102;
		color->g += 51;
	}
	else if (*iteration > 0)
	{
		color->r += (*iteration * 2);
		color->g += *iteration;
	}
	*iteration = *iteration - 51;
}

void	ft_color_original(t_data *data, int iteration, int largeur, int hauteur)
{
	t_color	color;

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
			original1(&color, &iteration);
			original2(&color, &iteration);
			original3(&color, &iteration);
			original4(&color, &iteration);
			original5(&color, &iteration);
			original6(&color, &iteration);
		}
		my_mlx_pixel_put(&data->img1, largeur, hauteur, \
		makecolor(color.t, color.r, color.g, color.b));
	}
}
