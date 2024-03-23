/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:38:18 by mjadid            #+#    #+#             */
/*   Updated: 2024/03/23 09:53:19 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_read(int fd, char *s)
{
	int		i;
	int		flag;
	char	*buff;
	int		charsread;

	i = 0;
	flag = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (to_free(&s));
	while (!flag)
	{
        charsread = read(fd, buff, BUFFER_SIZE);
		buff[charsread] = '\0';
        if (charsread <= 0)
		{
			free(buff);
			if (charsread == 0)
				return (s);
			return (to_free(&s));
		}
		s = ft_strjoin(s, buff);
		flag = is_exist(buff);
	}
	return (s);
}

char	*ft_linelimiter(char *str)
{
	int		i;
	size_t	len;
    char *line;
    
    i = 0;
	len = ft_strlen(str, '\n');
	line = malloc(len + 1);
	if (!line)
		return (to_free(&str));
	while (str[i] && i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (to_free(&s));
    s = to_read(fd, s);
    if(!s)
        return(to_free(&s));
	line = ft_linelimiter(s);
    // s = 
    return(line);
}
