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

int	ft_formule_mandelbrot(long double x, long double y, int max_iteration)
{
	t_math	t;
	int		i;

	t.c_r = x;
	t.c_i = y;
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	//printf("cr = %lf et c_i = %lf \n", c_r, c_i);

	while (t.z_r * t.z_r + t.z_i * t.z_i < 4 && i < max_iteration)
	{
		t.tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = 2 * t.z_i * t.tmp + t.c_i;
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

int	ft_formule_mandelbrot3(long double x, long double y, int max_iteration)
{
	t_math	t;
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

int	ft_formule_mandelbrot4(long double x, long double y, int max_iteration)
{
    long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
	int		i;

	c_r = x;
	c_i = y;
	z_r = 0;
	z_i = 0;
	i = 0;
    /*while ((z_r*z_r*z_r*z_r)  + (z_i*z_i*z_i*z_i)  < 4 && i < max_iteration)
    {
        tmp = z_r;
        z_r = z_r*z_r*z_r*z_r - 6*z_r*z_r*z_i*z_i + z_i*z_i*z_i*z_i + c_r;
        z_i = 4*tmp*tmp*tmp + c_i;
        i++;
    }*/
    while (z_r*z_r*z_r*z_r - 6*z_r*z_r*z_i*z_i + z_i*z_i*z_i*z_i + c_r < 4 && z_i*z_i*z_i*z_i - 6*z_i*z_i*z_r*z_r + c_i < 4 && i < max_iteration)
    {
        tmp = z_r;
        z_r = z_r*z_r*z_r*z_r - 6*z_r*z_r*z_i*z_i + z_i*z_i*z_i*z_i + c_r;
        z_i = 4*tmp*z_i*(z_r*z_r - z_i*z_i) + c_i;
        i++;
    }
    return (i);

}

int	ft_formule_mandelbrotn2(long double x, long double y, int max_iteration)
{
    long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
	long double d;
	int		i;

    c_r = x;
	c_i = y;
	z_r = 0;
	z_i = 0;
	i = 0;
    while (z_r * z_r + z_i * z_i >= 4 && i < max_iteration)
    {
		d = z_r*z_r*z_r*z_r + 2 * z_i*z_i+ z_i*z_i*z_i*z_i;
		if (d == 0)
			break ;
		tmp = (z_r * z_r - z_i * z_i) / d + c_r;
        z_i = -2 * z_r * z_i /d + c_i;
        z_r = tmp;
        i++;
    }
    return (i);
}

