/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:43 by kscordel          #+#    #+#             */
/*   Updated: 2022/12/01 16:34:12 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	lents(const char *str, char c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			t++;
		i++;
	}
	return (t);
}

static char	*cpy_tsx(const char *s, int index, char c)
{
	int		i;
	int		t;
	char	*str;

	i = index;
	t = 0;
	while (s[i] != c && s[i])
	{
		t++;
		i++;
	}
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[index] != c && s[index])
	{
		str[i] = s[index];
		i++;
		index++;
	}
	str[i] = '\0';
	return (str);
}

static void	*free_all(char **ts, int x)
{
	while (x >= 0)
	{
		free(ts[x]);
		x--;
	}
	free(ts);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ts;
	int		x;
	int		i;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	ts = malloc(sizeof(char *) * (lents(s, c) + 1));
	if (ts == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			ts[x] = cpy_tsx(s, i, c);
			if (ts[x] == NULL)
				return (free_all(ts, x));
			i += ft_strlen(ts[x]);
			x++;
		}
		i++;
	}
	ts[x] = 0;
	return (ts);
}
