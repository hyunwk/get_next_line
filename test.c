#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#include "get_next_line.h"
#include <string.h>

void test(int fd)
{
	char buf[99];
	
	printf("%p", &buf[0]);
}

int main(void)
{
	int fd;
	fd = 1;
	char buf[99];
	
	printf("%p", &buf[0]);
	for (int i=0;i<17;i++)
	/	test(fd);
}
