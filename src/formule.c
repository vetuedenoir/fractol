/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:28:55 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/21 14:28:57 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long double	ft_abs(long double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_formule_mandelbrot(long double x, long double y, int max_iteration, t_math t)
{
	int	i;

	t.c_r = x;
	t.c_i = y;
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	while (t.z_r * t.z_r + t.z_i * t.z_i < 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = 2 * t.z_i * t.tmp + t.c_i;
		i++;
	}
	return (i);
}

int	ft_formule_mandelbrotn2(long double x, long double y, int max_iteration, t_math t)
{
	int	i;

	t.c_r = x;
	t.c_i = y;
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	while (t.z_r * t.z_r + t.z_i * t.z_i < 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = -2 * t.z_i * t.tmp + t.c_i;
		i++;
	}
	return (i);
}

int	ft_burning_ship(long double x, long double y, int max_iteration, t_math t)
{
	int	i;

	t.c_r = x;
	t.c_i = y;
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	while (t.z_r * t.z_r + t.z_i * t.z_i <= 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = ft_abs(2 * t.z_i * t.tmp) + t.c_i;
		i++;
	}
	return (i);
}

int	ft_julia(long double x, long double y, int max_iteration, t_math t)
{
	int		i;

   	//t.c_r = -0.4;
	//t.c_i = 0.6;
	t.z_r = x;
	t.z_i = y;
	i = 0;
	while (t.z_r * t.z_r + t.z_i * t.z_i <= 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = 2 * t.z_i * t.tmp + t.c_i;
		i++;

	}
	return (i);
}

int	ft_formule_mandelbrot3(long double x, long double y, int max_iteration, t_math t)
{
	int		i;

	t.c_r = x;
	t.c_i = y;
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	while ((t.z_r * t.z_r * t.z_r) + (t.z_i * t.z_i * t.z_i) < 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r * t.z_r - 3 * t.z_r * t.z_i * t.z_i + t.c_r;
		t.z_i = 3 * t.tmp * t.tmp * t.z_i - t.z_i * t.z_i * t.z_i + t.c_i;
		i++;
	}
	return (i);
}

