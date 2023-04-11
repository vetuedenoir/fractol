/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:42:25 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/16 14:44:41 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MAJUSCULE "0123456789ABCDEF"
# define MINUSCULE "0123456789abcdef"

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *format, ...);
int	ft_instruct(const char *pindex, int *len, va_list ap);
int	ft_putp(unsigned long p);
int	ft_putstr(const char *str);
int	ft_putnbru_base(unsigned long nbr, const char *base);
int	ft_putnbru(unsigned int nbr);
int	ft_putnbr(int nbr);
int	ft_putchar(char c);

#endif
