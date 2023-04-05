#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int fd = open("./test.txt", O_RDONLY, 0);
	if( fd < 0) {
		printf("NOT READ\n");
	}

	char buf[11] = {0};

	ssize_t i = read(fd, buf, 10);
	while(i) {	
		printf("======READ======\n");
		printf("%s\n", buf);
		printf("======END=======\n");
		printf("%lu\n", i);
		memset(buf, 0, sizeof(buf));
		i = read(fd, buf, 10);
	}
	
	close(fd);
	return 0;
}
