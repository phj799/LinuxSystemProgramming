#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *abc(void* arg)
{
    int id = *(int*)arg + 1;
    if(id==1)
      printf("ABC\n");
    else if(id==2)
      printf("MINMIN\n");
    else if(id==3)
      printf("COCO\n");
    else if(id==4)
      printf("KFCKFC\n");

    return 0;
}

int main()
{
    pthread_t t[4];
    int id[4];

    for(int i = 0 ; i < 4; i++) {
      id[i] = i;
      pthread_create(&t[i], NULL, abc, &id[i]);
      pthread_join(t[0], NULL);
    }

    return 0;
}