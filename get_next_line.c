/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/24 11:22:02 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1

int				alloc_newline(char **line, char **bak, int newline_idx, int read)
{
	char		*temp;

	if (read == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (read == -1)
		return (-1);
	if (newline_idx <= 0)
		return (1);
	temp = 0;
	(*bak)[newline_idx] = 0;
	*line = ft_strdup(*bak);
	if (*((*bak) + newline_idx + 1))
		temp = ft_strdup(*bak + newline_idx + 1);
	free(*bak);
	*bak = temp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			read_size;
	int			newline_idx;
	char		buff[BUFFER_SIZE + 1];
	static char *bak;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if (!bak)
		bak = ft_strdup("");
	while ((newline_idx = is_newline(bak)) == -1)
	{
		if ((read_size = read(fd, buff, BUFFER_SIZE)) <= 0)
		//if ((read_size = read(fd, buff, BUFFER_SIZE)) == 0)
			break ;
		bak = ft_strjoin(bak, buff, read_size);
	}
	return (alloc_newline(line, &bak, is_newline(bak), read_size));
}

#include <stdio.h>
int main()
{
	int fd;
	int gnl_result;
	char *line;
	
	fd = open("a.txt", O_RDONLY);
	while ((gnl_result = get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line);	
		free(line);
	}
	if (gnl_result == 0)
		return (0);
	free(line);
	close(fd);
	return (0);
}
