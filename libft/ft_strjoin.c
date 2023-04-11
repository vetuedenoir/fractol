/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:41:19 by kscordel          #+#    #+#             */
/*   Updated: 2022/11/22 18:46:01 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t;
	int		i;
	int		p;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	p = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[p])
	{
		str[i + p] = s2[p];
		p++;
	}
	str[i + p] = '\0';
	return (str);
}
