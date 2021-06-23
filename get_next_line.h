/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:09:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/23 12:01:43 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

char			*ft_strdup(char *s1);
int				ft_strlen(char *s);
int				ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
int				is_newline(char *bak);
int				alloc_newline(char **line, char **bak, int newline_idx);
int				get_next_line(int fd, char **line);
#endif
