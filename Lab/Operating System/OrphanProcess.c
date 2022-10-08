#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t p;
    p = fork();
    if (p == 0) /*Child*/
    {
        sleep(50);
        printf("I am child having PID %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
    }
    else /*Parent*/
    {
        printf("I am parent having PID %d\n", getpid());
        printf("My child PID is %d\n", p);
    }
    return 0;
}