#include <stdio.h>
#include <stdlib.h>

void abc(void *v)
{
    int* p = (int*)v;

    printf("%d\n", *p);
}

int main()
{
    int x = 10;
    abc(&x);
    return 0;
}
