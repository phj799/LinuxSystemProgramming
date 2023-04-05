#include <stdio.h>
#include <signal.h>
#include <signal.h>
#include <unistd.h>

// 3초 안에 어떠한 입력도 하지 않으면 종료

void gogo()
{
  printf("SYSTEM ERROR\n");
  exit(1);
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, gogo);
  char buf[100];
  

  while(1) {
    alarm(3);
    printf("3 second\n");
    scanf("%s", buf);
    printf("%s\n", buf);
  }
  return 0;
}