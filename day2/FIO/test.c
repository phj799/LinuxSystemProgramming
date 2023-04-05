#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd = open("./cal.txt", O_RDWR, 0);
	if (fd < 0) {
		printf("[%s :: %d] FILE OPEN ERROR\n", __FILE__, __LINE__); 
		exit(1);
	}
	
	char buf[1000] = {0};
	read(fd, buf, 1000-1);

	int num = atoi(buf)*2;

	fd = open("./cal.txt", O_WRONLY|O_TRUNC, 0);

	printf("\n===[%d]===\n", num);
	sprintf(buf, "%d", num);

	write(fd, buf, strlen(buf));

	close(fd);

	return 0;
}
