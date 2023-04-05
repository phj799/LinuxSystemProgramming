#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void go1(int num)
{
  printf("\n[Button Clicked]\n");
}

void go2(int num)
{
  system("clear");
  printf("RESET\n");
}

void go3(int num)
{
  printf("BYE\n");
  exit(0); // 정상 종료
}

int main()
{
  setbuf(stdout, NULL);

  signal(SIGUSR1, go1);
  signal(SIGUSR2, go2);
  signal(SIGTERM, go3);

  while(1) {
    for(int i = 'A'; i < 'Z'; i++)
    {
      printf("%c", i);
      usleep(100*1000);
    }
    for(int i = 'Z'; i > 'A'; i--)
    {
      printf("%c", i);
      usleep(100*1000);
    }
  }
  return 0;
}