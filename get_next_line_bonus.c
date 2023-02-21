/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:29:01 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/02/21 08:26:39 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	char	*line;
	int		len;

	if (!str[0])
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	line = malloc((len * sizeof(char) + 1 + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*get_rest(char *str)
{
	int			len;
	int			len_rest;
	char		*rest;

	len = 0;
	len_rest = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = malloc((ft_strlen(str) - len) * sizeof(char) + 1);
	if (!rest)
		return (NULL);
	len++;
	while (str[len] != '\0')
		rest[len_rest++] = str[len++];
	rest[len_rest] = '\0';
	free(str);
	return (rest);
}

char	*get_buffer(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_buffer(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (line);
}
