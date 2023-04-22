/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:50:35 by kscordel          #+#    #+#             */
/*   Updated: 2023/04/22 19:51:25 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long double	ft_atof(char *str)
{
	long double	r;
	long	l;
	int	i;
	int	signe;

	signe = 1;
	l = 0;
	r = 0.0;
	i = 0;
	while (str[i] == 32 || str[i] <= 13 && str[i] >= 9)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		l = l * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r / 10.0 + str[i] - 48;
		i--;
	}
	return (((double)l + r / 10) * signe);
	printf("%d\n", i);
	printf("l = %ld et r = %.100Lf\n", l, r);
}


