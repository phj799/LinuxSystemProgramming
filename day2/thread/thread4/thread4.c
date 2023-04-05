#include <stdio.h>
#include <pthread.h>

pthread_t tid[4];

void *run(void *arg)
{
    int a = *(int *)arg;
    printf("%d", a);
}

int main()
{
    int num[38];
    for (int i = 1; i <= 37 ; i++)
    {
      num[i] = i;
      pthread_create(&tid[i], NULL, run, &num[i]);
    }
    for (int i = i; i <= 37; i++)
      pthread_join(tid[i], NULL);
    
    printf("VVCC END\n");
    return 0;
}