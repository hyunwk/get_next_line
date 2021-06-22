/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/22 10:25:48 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

int				alloc_newline(char **line, char *bak, int newline_idx)
{
	if (!(*line = (char *)malloc(sizeof(char) * newline_idx)))
		return (-1);
	bak[newline_idx] = 0;
	if (!(*line = ft_strdup(bak)))
		return (-1);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			read_size;
	int			newline_idx;
	char		buff[BUFFER_SIZE + 1];
	char static *bak;
	char		*temp;

	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = 0;
		bak = ft_strjoin(bak, buff);
		if ((newline_idx = is_newline(bak)) > 0)
		{
			if ((alloc_newline(line, bak, newline_idx)) == -1)
				return (-1);
//			if (!(*line = (char *)malloc(sizeof(char) * newline_idx)))
//				return (-1);
//			bak[newline_idx] = 0;
//			*line = ft_strdup(bak);
			temp = ft_strdup(bak + newline_idx + 1);
			bak = temp;
			return (1);
		}
	}
	return (0);
}

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
	{
		return (0);
	}
	return (0);
}
