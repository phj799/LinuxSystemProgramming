#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd = open("test.txt", O_WRONLY, 0666);

    lseek(fd, 3, SEEK_CUR);

    char buf[10] = "[NEW]";
    int n = strlen(buf);

    write(fd, buf, n);

    close(fd);
    return 0;
}
