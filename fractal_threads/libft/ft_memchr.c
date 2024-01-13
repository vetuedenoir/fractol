/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:31:20 by kscordel          #+#    #+#             */
/*   Updated: 2022/11/15 19:59:12 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*buf;

	i = 0;
	buf = s;
	while (i < n)
	{
		if (buf[i] == (unsigned char) c)
			return ((void *) &buf[i]);
		i++;
	}
	return (NULL);
}
