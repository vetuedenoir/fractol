/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:39:34 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/25 16:40:35 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_clear_data(t_data *data)
{
	if (data->img1.img)
		mlx_destroy_image(data->mlx, data->img1.img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

void	bad_arg(t_data *data, bool l)
{
	ft_printf("Mode d'emploie :\n");
	ft_printf("\t1) Ecrire ./fractol suivie des arguments suivant\n");
	ft_printf("\t - Mandelbrot soit Julia ou Burning_ship\n");
	ft_printf("\t - Mandelbrot peut etre suivie de 2 ou 3 pour avoir\
 les differentes variable\n");
	ft_printf("\t\texemple : ./fractol Mandelbrot 3\n");
	ft_printf("\t - Julia peut etre suivie de 2 argument\n");
	ft_printf("\t ->\tLe premier est un nombre representant la partie\
	reel de c\n");
	ft_printf("\t ->\tLe deuxieme est un nombre representant la partie\
 imaginaire de c\n");
	ft_printf("\t\texemple : ./fractol Julia -0.76 0.12\n\n");
	ft_printf("\t2) Les deplacement et ajustement\n");
	ft_printf("\t - Vous pouvez faire des petits zooms et dezoom avec la molette\
	de la souris\n\t   mais aussi des grands zooms avec le clic gauche\
 et des grands dezoom avec le clic drois\n");
	ft_printf("\t - Vous pouvez aussi vous deplacer en utilisant\
	 les 4 fleches\n");
	ft_printf("\t - Et augmenter les iterations avec la touche + et\
 les reduire avec la touche -\n");
	ft_printf("\t - De base l'iteration s'augmente de 1 ou se reduit de 1\n");
	ft_printf("\t - il est possible de multiplier ou diviser l augmentation par 10\n\
\t   pour aller plus vite en appuyant sur les touche * et /\n");
	ft_printf("\t - Enfin il est possible de masquer les informations sur le zoom\
 et les iterations avec la touche s\n\n");
	if (l)
		ft_clear_data(data);
}
