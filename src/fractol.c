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

static void	lennb(unsigned long nb, int *t)
{
	int	i;

	i = 0;
	if (nb == 0)
		*t = *t + 1;
	else
	{
		while (nb != 0)
		{
			nb /= 10;
			*t = *t + 1;
			i++;
			if (i % 3 == 0)
				*t = *t + 1;
		}
		if (i % 3 == 0)
			*t = *t - 1;
	}
}

char	*ft_itoal(unsigned long nb)
{
	int		t;
	int		i;
	char	*str;

	t = 0;
	i = 1;
	lennb(nb, &t);
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	str[t] = '\0';
	while (t > 0)
	{
		t--;
		if (t > 0 && i % 4 == 0)
			str[t] = 32;
		else
		{
			str[t] = nb % 10 + 48;
			nb /= 10;
		}
		i++;
	}
	return (str);
}

void	stringput(t_data *data)
{
	char	*s;
	char	*fs;

	s = ft_itoal(data->p.zoom);
	if (!s)
		return ;
	fs = ft_strjoin("ZOOM * ", s);
	free(s);
	if (fs)
		mlx_string_put(data->mlx, data->mlx_win, 0, 10, 0x808080, fs);
	free(fs);
	s = ft_itoal(data->max_iteration);
	if (!s)
		return ;
	fs = ft_strjoin("max_iteration = ", s);
	free(s);
	if (fs)
		mlx_string_put(data->mlx, data->mlx_win, 0, 20, 0x808080, fs);
	free(fs);
}

void	createimg(t_data *data , int (*f)(long double x, long double y, int max_iteration))
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
	if (data->b == 0)
		stringput(data);
}

void	createimg2(t_data *data , int (*f)(long double x, long double y, int max_iteration, t_math t))
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
			color = f((double)largeur / (double)data->p.zoom + data->p.x1, (double)hauteur / (double)data->p.zoom - data->p.y2, data->max_iteration, data->mt);
			color_put(data, color, largeur, hauteur);
			largeur++;
			//printf("largeur = %d et hauteur = %d\n",largeur, hauteur);
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
	
	if (argc == 1 || argc > 4)
		return (1);
	init_data(&data, argv[1], argv[2], argv[3]);
	if (!ft_strncmp(argv[1], "Julia", 6))
		createimg2(&data, data.f);
	else
		createimg(&data, data.f);
	loop(&data);
	return (1);
}
