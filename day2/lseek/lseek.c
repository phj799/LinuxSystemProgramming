#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("./test.txt", O_RDONLY, 0);
    if (fd < 0) {
        printf("FILE OPEN ERROR\n");
        exit(1);
    }

    char buf[11] = {0};
    int n;

    n = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", n);

    read(fd, buf, 10);

    n = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", n);

    close(fd);
    return 0;
}
