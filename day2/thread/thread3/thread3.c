#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct _NODE_
{
  int y;
  int x;
} Node;

void *abc(void *p)
{
  Node *val = (Node *)p;
  printf("%d %d\n", val->x, val->y);
}

int main()
{
  pthread_t tid;

  Node val = {2, 4};

  pthread_create(&tid, NULL, abc, &val);
  pthread_join(tid, NULL);

  return 0;
}