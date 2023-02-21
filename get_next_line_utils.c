/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:29:56 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/02/21 08:49:24 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		else
			i++;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	char		*s;

	if (len == 0 || dest == src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (len-- > 0)
		*d++ = *s++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;

	len = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	dest[len] = '\0';
	free(s1);
	return (dest);
}
