#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *DD1()
{
    while (1)
    {
        printf("[DD1] A\n");
        usleep(300*1000);
        printf("[DD1] B\n");
        usleep(300*1000);
        printf("[DD1] C\n");
        usleep(300*1000);
    }

    return 0;
}

void *DD2()
{
    while (1)
    {
        for(int i = 0 ; i <= 5; i++) {
          printf("[DD2] %d\n", i);
          usleep(200*1000);
        }
    }
    return 0;
}

void *DD3()
{
    while (1)
    {
        for(char ch = 'A' ; ch <= 'Z'; ch++) {
          printf("[DD3] %c\n", ch);
          usleep(200*1000);
        }
    }
    return 0;
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, DD1, NULL);
    pthread_create(&t2, NULL, DD2, NULL);
    pthread_create(&t3, NULL, DD3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}