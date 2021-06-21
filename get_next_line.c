/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/21 17:49:38 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len_src;

	if (!src)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while (i++ < dstsize - (size_t)1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (len_src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		idx;
	char	*ptr;

	if (!s1)
		return ((char *)s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	idx = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	free(s1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	// 추가
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!(*s))
			return (0);
		s++;
	}
	return ((char *)s);
}



int get_next_line(int fd, char **line)
{
	int read_size;
	int	idx;
	char buff[BUFFER_SIZE + 1];
	char static *bak;
	char	*temp;

	read_size = 0;
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = 0;
		bak = ft_strjoin(bak, buff);
		if (ft_strchr(bak,'\n'))
		{
			idx = 0;
			while (bak[idx] != '\n')
				idx++;
			if (!(*line = (char *)malloc(sizeof(char) * idx)))
				return (-1);
			bak[idx] = 0;
			*line = ft_strdup(bak);
			if (*(bak + idx + 1))
			{
				temp = ft_strdup(bak + idx + 1);
				bak = temp;
			}
			return (1);
		}
	}
	return 1;	
}
int main()
{
	int fd;
	int result;
	char *line;
	
	fd = open("a.txt", O_RDONLY);
	while ((result = get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line);	
		free(line);
	}
	return (0);
}
