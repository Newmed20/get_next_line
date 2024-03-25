/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:38:18 by mjadid            #+#    #+#             */
/*   Updated: 2024/03/25 02:59:12 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*to_read(int fd, char *s)
{
	int		i;
	int		flag;
	char	*buff;
	int		charsread;

	i = 0;
	flag = 0;
	while (!flag)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (to_free(&s));
		charsread = read(fd, buff, BUFFER_SIZE);
		buff[charsread] = '\0';
		if (charsread <= 0)
		{
			free(buff);
			if (charsread == 0)
				return (s);
			return (to_free(&s));
		}
		flag = is_exist(buff);
		s = ft_strjoin(s, buff);
	}
	return (s);
}

char	*ft_linelimiter(char *str)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = ft_strlen(str, '\n');
	line = malloc(len + 2);
	if (!line)
		return (to_free(&str));
	while (str[i] && i <= len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*to_update(char *str)
{
	int		len;
	int		i;
	size_t	linelen;
	char	*newstr;

	i = 0;
	linelen = ft_strlen(str, '\n');
	len = ft_strlen(str, '\0') - linelen - 1;
	if (len > 0)
	{
		newstr = malloc(len + 1);
		if (!newstr)
			return (to_free(&str));
		while (i < len)
		{
			newstr[i] = str[linelen + i + 1];
			i++;
		}
		newstr[i] = '\0';
	}
	else
		return (to_free(&str));
	to_free(&str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (to_free(&s[fd]));
	s[fd] = to_read(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = ft_linelimiter(s[fd]);
	s[fd] = to_update(s[fd]);
	return (line);
}
