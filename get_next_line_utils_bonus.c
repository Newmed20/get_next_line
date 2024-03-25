/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:50 by mjadid            #+#    #+#             */
/*   Updated: 2024/03/25 03:02:27 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i])
		i++;
	return (i);
}

size_t	is_exist(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		n;
	int		i;
	char	*copy;

	n = ft_strlen(s1, '\0') + 1;
	copy = malloc(n);
	i = 0;
	if (!copy)
		return (NULL);
	while (s1[i++])
		copy[i - 1] = s1[i - 1];
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	newstrlen;
	char	*newstr;

	if (!s1 && !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1, '\0');
	newstrlen = s1_len + ft_strlen(s2, '\0');
	newstr = malloc(newstrlen + 1);
	if (!newstr)
	{
		to_free(&s2);
		return (to_free(&s1));
	}
	while (s1 && s1[i++])
		newstr[i - 1] = s1[i - 1];
	i = 0;
	while (s2 && s2[i++])
		newstr[s1_len + (i - 1)] = s2[i - 1];
	newstr[newstrlen] = 0;
	to_free(&s1);
	return (newstr);
}

char	*to_free(char **str)
{
	free(*str);
	*str = 0;
	return (*str);
}
