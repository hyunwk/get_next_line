/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/06/21 00:04:56 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 4
int get_next_line(int fd, char **line)
{
	int result;
	char buff[BUFFER_SIZE];
	char static bak;

	result = read(fd, buff, BUFFER_SIZE);
	printf("buff:%s\n",buff);
	return 1;	
}

int main()
{
	int fd;
	int result;
	char *line;
	
	fd = open("a.txt", O_RDONLY);
	result = get_next_line(fd, &line);
}
