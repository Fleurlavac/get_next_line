/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaval <fcaval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:06:16 by fcaval            #+#    #+#             */
/*   Updated: 2025/11/27 13:28:15 by fcaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_this_please(int fd, char *save);
char	*where_is_the_line(char *save);
char	*save_this_please(char *save);
char	*get_next_line(int fd);
int		ft_strglen(const char *s);
char	*ft_strgchr(const char *s, int c);
char	*ft_strgjoin(char *s1, char *s2);

#endif