#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void *abc(){
  while(1);
  return 0;
}

int main(){
  pthread_t t[4];

  for(int i =0; i<4; i++) {
    pthread_create(&t[i], NULL, abc, NULL);
    sleep(3);
  }

  for(int i =0; i<4; i++) {
    pthread_join(t[i], NULL);
  }

  return 0;
}