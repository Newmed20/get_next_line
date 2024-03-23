/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:50 by mjadid            #+#    #+#             */
/*   Updated: 2024/03/23 09:36:35 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}
size_t	is_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char	*ft_strdup( char *s1)
{
	int		n;
	int		i;
	char	*copy;

	n = ft_strlen(s1 , '\0') + 1;
	copy = malloc(n);
	i = 0;
	if (!copy)
		return (NULL);
	while(s1[i++])
        copy[i-1] = s1[i-1];
	return (copy);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len;
	char	*newstr;
	int		i;
	int		j;
    
    if (str1 == NULL)
        return(ft_strdup(str2));
    
	// if (!str1 && str2)
	// 	return (to_free(&str1));
	len = ft_strlen(str1, '\0') + ft_strlen(str1, '\0');
	newstr = malloc(len + 1);
	i = 0;
	j = 0;
	while (str1[i++])
		newstr[i - 1] = str1[i - 1];
	i--;
	while (str2[j])
    {
		newstr[i + j] = str2[j];
        j++;
    }
	newstr[i + j - 1] = 0;
	return (newstr);
}

char	*to_free(char **str)
{
	free(*str);
	*str = 0;
	return (*str);
}
