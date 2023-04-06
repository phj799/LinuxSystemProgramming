#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main()
{
  time_t BBQ;

  char vect[10][10] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  while(1) {
    time(&BBQ);
    struct tm *tmm = localtime(&BBQ);
    printf("%d/%d/%d %s\n", 1900+tmm->tm_year, 1+tmm->tm_mon, tmm->tm_mday, vect[tmm->tm_wday]);
    printf("%d : %d : %d \n", tmm->tm_hour, tmm->tm_min, tmm->tm_sec);
    sleep(1);
  }
  

  return 0;
}