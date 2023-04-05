#include <stdio.h>
#include <unistd.h>

// 3초마다 # 무한 찍기 프로그램
// 의미없고 그냥 ps -ef, top, htop을 이용해서 findme App을 찾아보자

int main()
{
  setbuf(stdout, NULL);
  while(1)
  {
    printf("#");
    sleep(3);
  }
  return 0;
}
