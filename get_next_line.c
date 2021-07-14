/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/07/15 02:17:57 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	alloc_newline(char **line, char **bak, int nl_idx, int read)
{
	char		*temp;

	if (read == -1)
		return (-1);
	if (*bak && nl_idx >= 0)
	{
		temp = 0;
		(*bak)[nl_idx] = 0;
		*line = ft_strdup(*bak);
		if (*((*bak) + nl_idx + 1))
			temp = ft_strdup(*bak + nl_idx + 1);
		free(*bak);
		*bak = temp;
		return (1);
	}
	if (*bak)
	{
		*line = *bak;
		*bak = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	is_newline(char *bak)
{
	int			idx;

	idx = 0;
	if (bak)
	{
		while (bak[idx])
		{
			if (bak[idx] == '\n')
				return (idx);
			idx++;
		}
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	int			newline_idx;
	char		*buff;
	static char	*bak[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0 || fd > 255)
		return (-1);
	*line = 0;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	newline_idx = -1;
	while (newline_idx == -1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		bak[fd] = ft_strjoin(bak[fd], buff, read_size);
		newline_idx = is_newline(bak[fd]);
	}
	free(buff);
	return (alloc_newline(line, &bak[fd], is_newline(bak[fd]), read_size));
}
