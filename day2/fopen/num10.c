#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("./num.txt", O_RDONLY, 0);
	char buf[1000] = {0};
	read(fd, buf, 1000 - 1);

	printf("%d\n", atoi(buf)+10);

	close(fd);

	return 0;
}
