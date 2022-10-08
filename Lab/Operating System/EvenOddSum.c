#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int *arr, id, size, evensum = 0, oddsum = 0;
    printf("Please Enter array size :");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    printf("Please %d Elements :", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if ((arr[i]) % 2 == 0)
            evensum += arr[i];
        else
            oddsum += arr[i];
    }
    id = fork();
    if (id == 0)
        printf("(Child Process) Sum of Odd Elements is :%d\n", oddsum);
    else if (id > 0)
        printf("(Parent Process) Sum of Even Elements is :%d\n", evensum);
}