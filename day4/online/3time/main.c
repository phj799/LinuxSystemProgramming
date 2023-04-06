#include <stdio.h>
#include <time.h>

int main()
{
  time_t current_time = time(NULL);

  struct tm *tmm = localtime(&current_time);

  printf("min : %d\n", tmm->tm_min);

  return 0;
}