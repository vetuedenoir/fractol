/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:56 by kscordel          #+#    #+#             */
/*   Updated: 2022/11/15 14:03:54 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*bufd;
	const char	*bufs;

	bufd = dest;
	bufs = src;
	if (bufd <= bufs)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
			bufd[n] = bufs[n];
	}
	return (dest);
}
