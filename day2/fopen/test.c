#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int fd = open("./test.txt", O_RDWR, 600);
	if ( fd < 0) {
		printf("[%s :: %d] FILE OPEN ERROR\n", __FILE__, __LINE__);
		exit(1);
	}
}
