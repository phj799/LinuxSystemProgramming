#include <stdio.h>
#include <pthread.h>

char vect[4][21] = 
{
  "ABCDEFGHIJKLMNOPQRST",
  "HIFAKERHIFAKERHIFAKE",
  "BBQBBQBBQBBQBBQBBQBB",
  "MACMACMACMACMACMACMA",
};

void change(char* str) {
  for(int i = 0; str[i]; i++) {
    char ch = str[i];
    if(ch >= 'A' && ch <= 'W') {
      ch = ch + 3;
    }
    if(ch > 'W') {
      ch = ch - 23;
    }
    str[i] = ch;
  }
}

void* run(void *p) {
  int line = *(int*)p;
  change(vect[line]);
  return 0;
}


int main()
{
  pthread_t t[4];
  int id[4];

  for(int i = 0 ; i < 4; i++) {
    id[i] = i;
    pthread_create(&t[i], NULL, run, &id[i]);
  }

  for(int i =0; i < 4; i++) {
    pthread_join(t[i], NULL);
  }

  for(int i = 0; i < 4; i++) {
    printf("%s\n",vect[i]);
  }

  return 0;
}