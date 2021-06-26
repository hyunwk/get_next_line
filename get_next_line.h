/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:09:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/26 18:32:20 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char			*ft_strdup(char *s1);
int				ft_strlen(char *s);
int				ft_strlcpy(char *dst, char *src, int dstsize);
char			*ft_strjoin(char *s1, char *s2, int read_size);
void			*ft_memset(char *b, int c, int len);
int				is_newline(char *bak);
int				alloc_newline(char **line, char **bak, int nl_idx, int read);
int				get_next_line(int fd, char **line);

#endif
