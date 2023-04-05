#include <stdio.h>
#include <unistd.h>

int main()
{
  setbuf(stdout, NULL);
  while(1) {
    printf("1");
    usleep(300*1000);
  }
  return 0;
}