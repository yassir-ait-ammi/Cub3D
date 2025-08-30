/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:59:11 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/23 09:46:52 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include "libhb.h"

char	*get_next_line(int fd, int flax);
char	*ft_strdup(const char *s);
char	*ft_substr(char *str, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

#endif
