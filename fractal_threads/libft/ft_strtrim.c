/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:36:26 by kscordel          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:06 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	len;
	size_t	av;
	size_t	i;
	char	*str;

	av = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (checkchar(s1[av], set) && s1)
		av++;
	len = ft_strlen(s1);
	while (checkchar(s1[len - 1], set) && av < len)
		len--;
	str = malloc(sizeof(char) * (len - av + 1));
	if (!str)
		return (NULL);
	while (av < len)
		str[i++] = s1[av++];
	str[i] = '\0';
	return (str);
}
