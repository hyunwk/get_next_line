/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:09:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/22 10:17:36 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

char			*ft_strdup(const char *s1);
int				ft_strlen(const char *s);
int				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
int				is_newline(char *bak);
int				get_next_line(int fd, char **line);
#endif
