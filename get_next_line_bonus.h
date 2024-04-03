/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:51:04 by mjadid            #+#    #+#             */
/*   Updated: 2024/04/03 03:19:23 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line_bonus(int fd);
char	*to_read(int fd, char *s);
char	*ft_linelimiter(char *str);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str, char c);
size_t	is_exist(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*to_free(char **str);
char	*to_update(char *str);
#endif