/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:40:19 by kscordel          #+#    #+#             */
/*   Updated: 2022/11/23 13:19:37 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_signe(long *nb, int *signe, int *t)
{
	if (*nb < 0)
	{
		*signe = -1;
		*t = *t + 1;
		*nb = *nb * -1;
	}
	else
		*signe = 1;
}

static void	lennb(long nb, int *t)
{
	if (nb == 0)
		*t = *t + 1;
	else
	{
		while (nb != 0)
		{
			nb /= 10;
			*t = *t + 1;
		}
	}
}

char	*ft_itoa(int n)
{
	int		t;
	int		signe;
	long	nb;
	char	*str;

	t = 0;
	nb = n;
	ft_signe(&nb, &signe, &t);
	lennb(nb, &t);
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	str[t] = '\0';
	while (t > 0)
	{
		t--;
		str[t] = nb % 10 + 48;
		nb /= 10;
	}
	if (signe == -1)
		str[t] = '-';
	return (str);
}
