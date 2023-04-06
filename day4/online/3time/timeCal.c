#include<stdio.h>
#include<time.h>

int main() {
  clock_t start, end;
  int sum = 1;
  start = clock();
  for(int i = 0 ; i < 1e8; i++) {
    sum = sum >> 2;
  }
  end = clock();
  printf("%ld\n", end-start);
  return 0;
}