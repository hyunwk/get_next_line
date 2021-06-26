/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/26 21:37:10 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				alloc_newline(char **line, char **bak, int nl_idx, int read)
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

int				is_newline(char *bak)
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

int				get_next_line(int fd, char **line)
{
	int			read_size;
	int			newline_idx;
	char		*buff;
	static char *bak[256];

	*line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0 || fd > 255)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((newline_idx = is_newline(bak[fd])) == -1)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if ((read_size = read(fd, buff, BUFFER_SIZE)) <= 0)
			break ;
		if (!(bak[fd] = ft_strjoin(bak[fd], buff, read_size)))
		{
			free(buff);
			return (-1);
		}
	}
	free(buff);
	return (alloc_newline(line, &bak[fd], is_newline(bak[fd]), read_size));
}
