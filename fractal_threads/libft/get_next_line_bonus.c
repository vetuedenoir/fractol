/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:55 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/16 16:30:50 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_testreturn(const char *s, char f)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	if (f)
		return (i);
	return (0);
}

char	*ft_read_file(char *stash, int fd)
{
	char	*buf;
	int		index;
	int		readed;
	int		total;

	total = ft_length(stash);
	readed = 0;
	index = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!index)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed || readed == -1)
			break ;
		buf[readed] = '\0';
		index = ft_testreturn(buf, 0);
		total += readed;
		stash = ft_add_buf(stash, buf, total);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	size_t		index;
	size_t		t;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	index = 0;
	t = 0;
	if (stash[fd])
		index = ft_testreturn(stash[fd], 0);
	if (!index)
		stash[fd] = ft_read_file(stash[fd], fd);
	if (stash[fd])
		line = ft_copy(stash[fd], &t);
	else
		return (NULL);
	stash[fd] = ft_clean(stash[fd], t);
	return (line);
}
