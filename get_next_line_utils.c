/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:09:07 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/22 10:16:10 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

char			*ft_strdup(const char *s1)
{
	char		*ptr;
	int			len;

	len = 0;
	while (s1[len])
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ptr - len);
}

int			ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int			ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int		i;
	int		len_src;

	if (!src)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while (i++ < dstsize - (int)1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (len_src);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int			len_s1;
	int			len_s2;
	int			idx;
	char		*ptr;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	idx = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	free(s1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	return (ptr);
}

int				is_newline(char *bak)
{
	int			idx;

	idx = 0;
	while (bak[idx] != '\n')
		idx++;
	if (idx == ft_strlen(bak))
		return (-1);
	return (idx);
}
