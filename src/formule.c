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

long double	powx(long double x, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    long double result = 1;
    int minus = 1;

    if (n < 0) {
        minus = -1;
        n = -n;
    }

    if (0 == n) {
        return 1;
    } else if (0 == x) {
        return 0;
    }
    
    while (n) {
        if (n & 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }

    if (minus < 0) {
        return 1.0 / result;
    } else {
        return result;
    }
}

long double	ft_power(long double nb, int power)
{
	int	i;
	long double	o;

	i = 0;
	o = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (i < power)
	{
		nb *= o;
		i++;
	}
	return (nb);
}

/*
long double	power(long double nb, int power)
{
	if (power == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	if (power >= 1)
	{
		return (power((nb * nb), power -1));
	}	
	else
		return (0);
}
*/

int	ft_formule_mandelbrot(long double x, long double y, int max_iteration)
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
	//printf("cr = %lf et c_i = %lf \n", c_r, c_i);

	while (z_r * z_r + z_i * z_i < 4 && i < max_iteration)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}


int	ft_formule_mandelbrot3(long double x, long double y, int max_iteration)
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
	while ((z_r * z_r * z_r) + (z_i * z_i * z_i) < 4 && i < max_iteration)
	{
		tmp = z_r;
		z_r = z_r*z_r*z_r - 3*z_r*z_i*z_i + c_r;
		z_i = 3*tmp*tmp*z_i - z_i*z_i*z_i + c_i;
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
	int		i;

    c_r = x;
	c_i = y;
	z_r = 0;
	z_i = 0;
	i = 0;
    while (z_r * z_r + z_i * z_i <= 4 && i < max_iteration)
    {
        tmp = powx(z_r, 2) - powx(z_i, 2) + c_r;
		//tmp = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_r * z_i + c_i;
        z_r = tmp;
        i++;
    }
    return (i);
}

