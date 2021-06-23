/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/22 21:59:30 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1 

int				alloc_newline(char **line, char *bak, int newline_idx)
{
	char		*temp;

	if (!(*line = (char *)malloc(sizeof(char) * newline_idx)))
	{
		free(bak);
		return (-1);
	}
	bak[newline_idx] = 0;
	if (!(*line = ft_strdup(bak)))
	{
		free(bak);
		return (-1);
	}
	if (*(bak + newline_idx + 1))
	{
		temp = ft_strdup(bak + newline_idx + 1);
		bak = temp;
	}
	else
	{
		free(bak);
		bak = ft_strdup("");
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			read_size;
	int			newline_idx;
	char		buff[BUFFER_SIZE + 1];
	char static *bak;

	while ((newline_idx = is_newline(bak)) <= 0 )
	{
		if ((read_size = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[read_size] = 0;
		bak = ft_strjoin(bak, buff);
	}
	if ((newline_idx == is_newline(bak)) > 0)
		return (alloc_newline(line, bak, newline_idx));
	return (1);
//	while 
//	{
//		buff[read_size] = 0;
//		bak = ft_strjoin(bak, buff);
//		if (!bak || ((newline_idx = is_newline(bak)) > 0))
//			break;
//	}
//	if (((newline_idx = is_newline(bak)) == -1) && !bak)
//		return (0);
//	if ((alloc_newline(line, &bak, newline_idx) == -1))
//		return (-1);
//	return (1); 
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
