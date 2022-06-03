/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:27:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/18 18:03:09 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getline(char **reminder, int fd)
{
	char	*line;
	int		linelen;
	char	*eolptr;

	eolptr = ft_strchr(reminder[fd], '\n');
	if (eolptr)
	{
		linelen = eolptr - reminder[fd] + 1;
		line = malloc(sizeof(char) * (linelen + 1));
		if (!line)
			return (NULL);
		line[linelen] = '\0';
		ft_strlcpy(line, reminder[fd], linelen + 1);
	}
	else
		line = ft_strdup(reminder[fd]);
	if (eolptr && *(eolptr + 1))
		ft_strlcpy(reminder[fd], eolptr + 1, ft_strlen(eolptr + 1) + 1);
	else
	{
		free(reminder[fd]);
		reminder[fd] = NULL;
	}
	return (line);
}

int	ft_read(char **reminder, int fd, char *buf)
{
	char	*tmp;
	int		rdlen;

	rdlen = read(fd, buf, BUFFER_SIZE);
	while (rdlen > 0)
	{
		buf[rdlen] = '\0';
		if (!reminder[fd])
			reminder[fd] = ft_strdup(buf);
		else
		{
			tmp = reminder[fd];
			reminder[fd] = ft_strjoin(reminder[fd], buf);
			free(tmp);
			tmp = NULL;
		}
		if (ft_strchr(reminder[fd], '\n'))
			break ;
		rdlen = read(fd, buf, BUFFER_SIZE);
	}
	return (rdlen);
}

char	*get_next_line(int fd)
{
	static char	*reminder[OPEN_MAX + 1];
	char		*buf;
	int			rdlen;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	rdlen = ft_read(reminder, fd, buf);
	free(buf);
	if (rdlen < 0)
		return (NULL);
	if (reminder[fd] && *reminder[fd])
		return (ft_getline(reminder, fd));
	return (NULL);
}
