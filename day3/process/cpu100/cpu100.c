#include <stdio.h>
#include <pthread.h>

// htop으로 cpu 코어 4개가 100%되는 걸 보자
void* loop() {
  while(1)
  {
  }
}

int main() {
  pthread_t t[4];

  for(int i = 0; i < 4; i++) {
    pthread_create(&t[i], NULL, loop, NULL);
  }

      
  for(int i = 0; i < 4; i++) {
    pthread_join(t[i], NULL);
  }
  return 0;
}
