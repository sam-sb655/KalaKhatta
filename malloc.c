#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr = (int *)malloc(sizeof(int) * 5);
    if (ptr == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }
    return 0;
}