/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:40:04 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/06 12:29:38 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbru_base(unsigned long nbr, const char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbru_base(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putnbru(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putnbru(nbr / 10);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}

int	ft_putnbr(int nbr)
{
	int		count;
	long	nb;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + 48);
	return (count);
}
